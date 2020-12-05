#include "Controller.h"

//現在のページ番号を返す
int Controller::returnCurrentPage()
{
	return cur_page;
}

//総ページ数を返す
int Controller::returnMaxPage()
{
	return max_page;
}

//ページ情報を読み込む
void Controller::initReadPage()
{
	makeReadFilePath(1);
	readPageJson();
}

//新規ページを作成
void Controller::createPage()
{
	makeFilePath();
	writePageJson();
	cur_page++;
	max_page++;
	init();
}

//現在のページを削除
void Controller::deletePage()
{
	//総ページ数マイナス1
	max_page--;
	if (max_page <= 0)
	{
		max_page = 1;
	}
	//現在のページ情報と一時情報を削除
	makeFilePath();
	FileSystem::Remove(path, true);
	makeTempPath();
	FileSystem::Remove(path, true);

	//現在のページ番号マイナス1
	cur_page--;
	//ページ数が不正な値になった場合，
	if (cur_page <= 0)
	{
		//2ページ目を読む
		makeReadFilePath(2);
		readPageJson();
		makeFilePath();
		FileSystem::Remove(path, true);
		makeTempPath();
		FileSystem::Remove(path, true);
		//1ページ目として書き込む
		makeFilePath(cur_page = 1);
		writePageJson();
	}
	else
	{
		//更新後のページ情報を読み込む
		makeReadFilePath();
		readPageJson();
	}
}

//全ての一時ページ情報を保存
void Controller::savePage()
{
	//現在のページから保存, そうしないと一時情報が上手く書き込めない
	makeFilePath();
	writePageJson();
	makeTempPath();
	if (FileSystem::Exists(path))
	{
		FileSystem::Remove(path, true);
	}
	//全ページ走査
	for (auto page = 1; page <= max_page; page++)
	{
		if (page == cur_page) continue;
		makeReadFilePath(page);
		readPageJson();
		makeFilePath(page);
		writePageJson();
		makeTempPath(page);
		if (FileSystem::Exists(path))
		{
			FileSystem::Remove(path, true);
		}
	}
	makeReadFilePath();
	readPageJson();
}

//一時情報を，上書きして変更をリセット
void Controller::resetPage()
{
	makeReadFilePath();
	readPageJson();
}

//次ページへ遷移
void Controller::nextPage()
{
	cur_page++;
	//総ページ数以上になったら
	if (cur_page > max_page)
	{
		//情報を更新しない
		cur_page = max_page;
	}
	else
	{
		//遷移前のページ情報を一時情報としてファイルに保存
		makeTempPath(cur_page - 1);
		writePageJson();
		//遷移後のページ情報を読む
		makeReadFilePath();
		readPageJson();
	}
}

//前ページへ遷移
void Controller::prevPage()
{
	cur_page--;
	//不正なページ数になったら
	if (cur_page <= 0)
	{
		//情報を更新しない
		cur_page = 1;
	}
	else
	{
		//遷移前のページ情報を一時情報としてファイルに保存
		makeTempPath(cur_page + 1);
		writePageJson();
		//遷移後のページ情報を読む
		makeReadFilePath();
		readPageJson();
	}
}

//編集結果をBookアプリ実行によって確認
void Controller::runBook()
{
	makeTempPath();
	writePageJson();
	//Bookアプリのパス
	const FilePath path = U"Page/PictureBook.exe";
	//別プロセスで起動
	ChildProcess child = Process::Spawn(path);
	if (!child)
	{
		throw Error(U"Failed to create a process");
	}
}

//エクスプローラーを開いて，選択したファイルの絶対パスを保存
//TODO: 画像ファイル以外の拡張子を省く機能を追加しないと，フリーズする
void Controller::selectImg(const int& idx)
{
	if (const auto open = Dialog::OpenFile())
	{
		img_inf[idx].path = open.value();
		//変更したことを通知
		img_inf[idx].flags.flag_p = true;
	}
}

//ファイルのパスを空文字にして，削除したことにする
void Controller::deleteImg(const int& idx)
{
	img_inf[idx].path = U"";
	img_inf[idx].flags.flag_p = true;
}

//変更された画像のサイズを保存
void Controller::changeImgSize(const int& idx, const double& size)
{
	img_inf[idx].size = size;
	img_inf[idx].flags.flag_s = true;
}

//変更された画像の不透明度を保存
void Controller::changeImgAlpha(const int& idx, const double& alpha)
{
	img_inf[idx].alpha = alpha;
	img_inf[idx].flags.flag_a = true;
}

//変更された画像の描画開始タイミングを保存
void Controller::changeImgFadein(const int& idx, const double& fadein)
{
	img_inf[idx].fadein = fadein;
}

//画像情報の受け渡し
ImgInf* Controller::returnImgInf(const int& idx)
{
	if (img_inf[idx].flags.eventFlag())
	{
		return &img_inf[idx];
	}

	return nullptr;
}

//変更された文字を保存
void Controller::changeTxt(const int& idx, String& txt)
{
	txt_inf[idx].txt = txt;
	txt_inf[idx].flags.flag_t = true;
}

//空文字を保存することで，削除したことにする
void Controller::deleteTxt(const int& idx)
{
	txt_inf[idx].txt = U"";
	txt_inf[idx].flags.flag_t = true;
}

//変更された文字サイズを保存
void Controller::changeTxtSize(const int& idx, const double& size)
{
	txt_inf[idx].size = size;
	txt_inf[idx].flags.flag_s = true;
}

//変更された文字の描画開始タイミングを保存
void Controller::changeTxtFadein(const int& idx, const double& fadein)
{
	txt_inf[idx].fadein = fadein;
}

//文字情報の受け渡し
TxtInf* Controller::returnTxtInf(const int& idx)
{
	if (txt_inf[idx].flags.eventFlag())
	{
		return &txt_inf[idx];
	}

	return nullptr;
}

//編集画面の矩形描画位置を返す
Vec2 Controller::returnBasePos()
{
	return base_pos;
}

//編集画面の矩形描画位置を変更し，保存
void Controller::changePos(Vec2& base)
{
	base_pos = base;
}

//画像や文字の描画位置を変更し，保存
void Controller::changePos(const int& idx, Vec2& pos)
{
	if (idx < 3)
	{
		img_inf[idx].pos = pos;
	}
	else
	{
		//画像情報と文字情報の配列が別なので，添え字をリセット
		auto txt_idx = idx % 3;
		txt_inf[txt_idx].pos = pos;
	}
}

//コンストラクタで呼ばれる初期化処理
void Controller::init()
{
	base_pos = Vec2::Zero();
	img_inf.clear();
	txt_inf.clear();
	img_inf.resize(3);
	txt_inf.resize(2);
	setInitFlag();
}

//変更フラグを全てtrueにする
void Controller::setInitFlag()
{
	for (auto& inf : img_inf)
	{
		inf.flags.reInit();
	}
	for (auto& inf : txt_inf)
	{
		inf.flags.reInit();
	}
}

//ファイル読み込み時のパスを作成
void Controller::makeReadFilePath()
{
	//一時情報ファイルがあれば，そっちを読み込む
	makeTempPath();
	if (!FileSystem::Exists(path))
	{
		makeFilePath();
	}
}

//ファイル読み込み時のパスを作成，ページ指定ができる
void Controller::makeReadFilePath(const int& page)
{
	makeTempPath(page);
	if (!FileSystem::Exists(path))
	{
		makeFilePath(page);
	}
}

//ファイルパスを作成
void Controller::makeFilePath()
{
	path = U"Page/page{}.json"_fmt(cur_page);
}

//ファイルパスを作成，ページ指定ができる
void Controller::makeFilePath(const int& page)
{
	path = U"Page/page{}.json"_fmt(page);
}

//一時情報ファイルパスを作成
void Controller::makeTempPath()
{
	path = U"Page/temp{}.json"_fmt(cur_page);
}

//一時情報ファイルパスを作成，ページ指定ができる
void Controller::makeTempPath(const int& page)
{
	path = U"Page/temp{}.json"_fmt(page);
}

//情報をJSONファイルに書き込む
void Controller::writePageJson()
{
	JSONWriter writer;
	writer.startObject();
	{
		writer.key(U"MaxPage").write(max_page);
		writer.key(U"PageBasePos").write(base_pos);
		writer.key(U"Image").startObject();
		{
			writer.key(U"img1").startObject();
			{
				writer.key(U"size").write(img_inf[0].size);
				writer.key(U"alpha").write(img_inf[0].alpha);
				writer.key(U"fadein").write(img_inf[0].fadein);
				writer.key(U"path").write(img_inf[0].path);
				writer.key(U"pos").write(img_inf[0].pos);
			}
			writer.endObject();
			writer.key(U"img2").startObject();
			{
				writer.key(U"size").write(img_inf[1].size);
				writer.key(U"alpha").write(img_inf[1].alpha);
				writer.key(U"fadein").write(img_inf[1].fadein);
				writer.key(U"path").write(img_inf[1].path);
				writer.key(U"pos").write(img_inf[1].pos);
			}
			writer.endObject();
			writer.key(U"img3").startObject();
			{
				writer.key(U"size").write(img_inf[2].size);
				writer.key(U"alpha").write(img_inf[2].alpha);
				writer.key(U"fadein").write(img_inf[2].fadein);
				writer.key(U"path").write(img_inf[2].path);
				writer.key(U"pos").write(img_inf[2].pos);
			}
			writer.endObject();
		}
		writer.endObject();
		writer.key(U"Scenario").startObject();
		{
			writer.key(U"txt1").startObject();
			{
				writer.key(U"size").write(txt_inf[0].size);
				writer.key(U"fadein").write(txt_inf[0].fadein);
				writer.key(U"txt").write(txt_inf[0].txt);
				writer.key(U"pos").write(txt_inf[0].pos);
			}
			writer.endObject();
			writer.key(U"txt2").startObject();
			{
				writer.key(U"size").write(txt_inf[1].size);
				writer.key(U"fadein").write(txt_inf[1].fadein);
				writer.key(U"txt").write(txt_inf[1].txt);
				writer.key(U"pos").write(txt_inf[1].pos);
			}
			writer.endObject();
		}
		writer.endObject();
	}
	writer.endObject();
	writer.save(path);
}

//JSONファイル読み込み
void Controller::readPageJson()
{
	JSONReader json(path);
	if (!json)
	{
		//作成したファイルが一切ないとき，初期ファイルを読み込む
		json = JSONReader(U"initialize.json");
		if (!json)
		{
			throw Error(U"failed to open json file");
		}
	}

	for (const auto& inf : json.objectView())
	{
		if (inf.name == U"MaxPage")
		{
			if (is_boot)
			{
				max_page = inf.value.get<int>();
				is_boot = false;
			}
		}
		else if (inf.name == U"PageBasePos")
		{
			base_pos = inf.value.get<Vec2>();
		}
		else if (inf.name == U"Image")
		{
			auto idx = 0;
			for (const auto& sub_inf : inf.value.objectView())
			{
				img_inf[idx].size = sub_inf.value[U"size"].get<double>();
				img_inf[idx].alpha = sub_inf.value[U"alpha"].get<double>();
				img_inf[idx].fadein = sub_inf.value[U"fadein"].get<double>();
				img_inf[idx].path = sub_inf.value[U"path"].getString();
				img_inf[idx].pos = sub_inf.value[U"pos"].get<Vec2>();
				idx++;
			}
		}
		else if (inf.name == U"Scenario")
		{
			auto idx = 0;
			for (const auto& sub_inf : inf.value.objectView())
			{
				txt_inf[idx].size = sub_inf.value[U"size"].get<double>();
				txt_inf[idx].fadein = sub_inf.value[U"fadein"].get<double>();
				txt_inf[idx].txt = sub_inf.value[U"txt"].getString();
				txt_inf[idx].pos = sub_inf.value[U"pos"].get<Vec2>();
				idx++;
			}
		}
	}
	setInitFlag();
}

//一時情報ファイルを削除，デストラクタで呼ばれる(Bookでは無効)
void Controller::deleteTempJson()
{
	for (auto page = 1; page <= max_page; page++)
	{
		makeTempPath(page);
		if (FileSystem::Exists(path))
		{
			FileSystem::Remove(path, true);
		}
	}
}