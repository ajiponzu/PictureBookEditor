#include "Controller.h"

int Controller::returnCurrentPage()
{
	return cur_page;
}

int Controller::returnMaxPage()
{
	return max_page;
}

void Controller::initReadPage()
{
	makeReadFilePath(1);
	readPageJson();
}

void Controller::createPage()
{
	makeFilePath();
	writePageJson();
	cur_page++;
	max_page++;
	init();
}

void Controller::deletePage()
{
	max_page--;
	if (max_page <= 0)
	{
		max_page = 1;
	}
	makeFilePath();
	FileSystem::Remove(path, true);
	makeTempPath();
	FileSystem::Remove(path, true);

	cur_page--;
	if (cur_page <= 0)
	{
		makeReadFilePath(2);
		readPageJson();
		makeFilePath();
		FileSystem::Remove(path, true);
		makeTempPath();
		FileSystem::Remove(path, true);
		makeFilePath(cur_page = 1);
		writePageJson();
	}
	else
	{
		makeReadFilePath();
		readPageJson();
	}
}

void Controller::savePage()
{
	makeFilePath();
	writePageJson();
	makeTempPath();
	if (FileSystem::Exists(path))
	{
		FileSystem::Remove(path, true);
	}
}

void Controller::resetPage()
{
	makeReadFilePath();
	readPageJson();
}

void Controller::nextPage()
{
	cur_page++;
	if (cur_page > max_page)
	{
		cur_page = max_page;
	}
	else
	{
		makeTempPath(cur_page - 1);
		writePageJson();
		makeReadFilePath();
		readPageJson();
	}
}

void Controller::prevPage()
{
	cur_page--;
	if (cur_page <= 0)
	{
		cur_page = 1;
	}
	else
	{
		makeTempPath(cur_page + 1);
		writePageJson();
		makeReadFilePath();
		readPageJson();
	}
}

void Controller::selectImg(const int& idx)
{
	if (const auto open = Dialog::OpenFile())
	{
		img_inf[idx].path = open.value();
		img_inf[idx].flags.flag_p = true;
	}
}

void Controller::deleteImg(const int& idx)
{
	img_inf[idx].path = U"";
	img_inf[idx].flags.flag_p = true;
}

void Controller::changeImgSize(const int& idx, const double& size)
{
	img_inf[idx].size = size;
	img_inf[idx].flags.flag_s = true;
}

void Controller::changeImgAlpha(const int& idx, const double& alpha)
{
	img_inf[idx].alpha = alpha;
	img_inf[idx].flags.flag_a = true;
}

void Controller::changeImgFadein(const int& idx, const double& fadein)
{
	img_inf[idx].fadein = fadein;
}

ImgInf* Controller::returnImgInf(const int& idx)
{
	if (img_inf[idx].flags.eventFlag())
	{
		return &img_inf[idx];
	}

	return nullptr;
}

void Controller::changeTxt(const int& idx, String& txt)
{
	txt_inf[idx].txt = txt;
	txt_inf[idx].flags.flag_t = true;
}

void Controller::deleteTxt(const int& idx)
{
	txt_inf[idx].txt = U"";
	txt_inf[idx].flags.flag_t = true;
}

void Controller::changeTxtSize(const int& idx, const double& size)
{
	txt_inf[idx].size = size;
	txt_inf[idx].flags.flag_s = true;
}

void Controller::changeTxtFadein(const int& idx, const double& fadein)
{
	txt_inf[idx].fadein = fadein;
}

TxtInf* Controller::returnTxtInf(const int& idx)
{
	if (txt_inf[idx].flags.eventFlag())
	{
		return &txt_inf[idx];
	}

	return nullptr;
}

Vec2 Controller::returnBasePos()
{
	return base_pos;
}

void Controller::changePos(Vec2& base)
{
	base_pos = base;
}

void Controller::changePos(const int& idx, Vec2& pos)
{
	if (idx < 3)
	{
		img_inf[idx].pos = pos;
	}
	else
	{
		auto txt_idx = idx % 3;
		txt_inf[txt_idx].pos = pos;
	}
}

void Controller::init()
{
	base_pos = Vec2::Zero();
	img_inf.clear();
	txt_inf.clear();
	img_inf.resize(3);
	txt_inf.resize(2);
	setInitFlag();
}

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

void Controller::makeReadFilePath()
{
	makeTempPath();
	if (!FileSystem::Exists(path))
	{
		makeFilePath();
	}
}

void Controller::makeReadFilePath(const int& page)
{
	makeTempPath(page);
	if (!FileSystem::Exists(path))
	{
		makeFilePath(page);
	}
}

void Controller::makeFilePath()
{
	path = U"Page/page{}.json"_fmt(cur_page);
}

void Controller::makeFilePath(const int& page)
{
	path = U"Page/page{}.json"_fmt(page);
}

void Controller::makeTempPath()
{
	path = U"Page/temp{}.json"_fmt(cur_page);
}

void Controller::makeTempPath(const int& page)
{
	path = U"Page/temp{}.json"_fmt(page);
}

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

void Controller::readPageJson()
{
	JSONReader json(path);
	if (!json)
	{
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