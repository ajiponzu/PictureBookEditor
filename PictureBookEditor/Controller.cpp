#include "Controller.h"

//���݂̃y�[�W�ԍ���Ԃ�
int Controller::returnCurrentPage()
{
	return cur_page;
}

//���y�[�W����Ԃ�
int Controller::returnMaxPage()
{
	return max_page;
}

//�y�[�W����ǂݍ���
void Controller::initReadPage()
{
	makeReadFilePath(1);
	readPageJson();
}

//�V�K�y�[�W���쐬
void Controller::createPage()
{
	makeFilePath();
	writePageJson();
	cur_page++;
	max_page++;
	init();
}

//���݂̃y�[�W���폜
void Controller::deletePage()
{
	//���y�[�W���}�C�i�X1
	max_page--;
	if (max_page <= 0)
	{
		max_page = 1;
	}
	//���݂̃y�[�W���ƈꎞ�����폜
	makeFilePath();
	FileSystem::Remove(path, true);
	makeTempPath();
	FileSystem::Remove(path, true);

	//���݂̃y�[�W�ԍ��}�C�i�X1
	cur_page--;
	//�y�[�W�����s���Ȓl�ɂȂ����ꍇ�C
	if (cur_page <= 0)
	{
		//2�y�[�W�ڂ�ǂ�
		makeReadFilePath(2);
		readPageJson();
		makeFilePath();
		FileSystem::Remove(path, true);
		makeTempPath();
		FileSystem::Remove(path, true);
		//1�y�[�W�ڂƂ��ď�������
		makeFilePath(cur_page = 1);
		writePageJson();
	}
	else
	{
		//�X�V��̃y�[�W����ǂݍ���
		makeReadFilePath();
		readPageJson();
	}
}

//�S�Ă̈ꎞ�y�[�W����ۑ�
void Controller::savePage()
{
	//���݂̃y�[�W����ۑ�, �������Ȃ��ƈꎞ��񂪏�肭�������߂Ȃ�
	makeFilePath();
	writePageJson();
	makeTempPath();
	if (FileSystem::Exists(path))
	{
		FileSystem::Remove(path, true);
	}
	//�S�y�[�W����
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

//�ꎞ�����C�㏑�����ĕύX�����Z�b�g
void Controller::resetPage()
{
	makeReadFilePath();
	readPageJson();
}

//���y�[�W�֑J��
void Controller::nextPage()
{
	cur_page++;
	//���y�[�W���ȏ�ɂȂ�����
	if (cur_page > max_page)
	{
		//�����X�V���Ȃ�
		cur_page = max_page;
	}
	else
	{
		//�J�ڑO�̃y�[�W�����ꎞ���Ƃ��ăt�@�C���ɕۑ�
		makeTempPath(cur_page - 1);
		writePageJson();
		//�J�ڌ�̃y�[�W����ǂ�
		makeReadFilePath();
		readPageJson();
	}
}

//�O�y�[�W�֑J��
void Controller::prevPage()
{
	cur_page--;
	//�s���ȃy�[�W���ɂȂ�����
	if (cur_page <= 0)
	{
		//�����X�V���Ȃ�
		cur_page = 1;
	}
	else
	{
		//�J�ڑO�̃y�[�W�����ꎞ���Ƃ��ăt�@�C���ɕۑ�
		makeTempPath(cur_page + 1);
		writePageJson();
		//�J�ڌ�̃y�[�W����ǂ�
		makeReadFilePath();
		readPageJson();
	}
}

//�ҏW���ʂ�Book�A�v�����s�ɂ���Ċm�F
void Controller::runBook()
{
	makeTempPath();
	writePageJson();
	//Book�A�v���̃p�X
	const FilePath path = U"Page/PictureBook.exe";
	//�ʃv���Z�X�ŋN��
	ChildProcess child = Process::Spawn(path);
	if (!child)
	{
		throw Error(U"Failed to create a process");
	}
}

//�G�N�X�v���[���[���J���āC�I�������t�@�C���̐�΃p�X��ۑ�
//TODO: �摜�t�@�C���ȊO�̊g���q���Ȃ��@�\��ǉ����Ȃ��ƁC�t���[�Y����
void Controller::selectImg(const int& idx)
{
	if (const auto open = Dialog::OpenFile())
	{
		img_inf[idx].path = open.value();
		//�ύX�������Ƃ�ʒm
		img_inf[idx].flags.flag_p = true;
	}
}

//�t�@�C���̃p�X���󕶎��ɂ��āC�폜�������Ƃɂ���
void Controller::deleteImg(const int& idx)
{
	img_inf[idx].path = U"";
	img_inf[idx].flags.flag_p = true;
}

//�ύX���ꂽ�摜�̃T�C�Y��ۑ�
void Controller::changeImgSize(const int& idx, const double& size)
{
	img_inf[idx].size = size;
	img_inf[idx].flags.flag_s = true;
}

//�ύX���ꂽ�摜�̕s�����x��ۑ�
void Controller::changeImgAlpha(const int& idx, const double& alpha)
{
	img_inf[idx].alpha = alpha;
	img_inf[idx].flags.flag_a = true;
}

//�ύX���ꂽ�摜�̕`��J�n�^�C�~���O��ۑ�
void Controller::changeImgFadein(const int& idx, const double& fadein)
{
	img_inf[idx].fadein = fadein;
}

//�摜���̎󂯓n��
ImgInf* Controller::returnImgInf(const int& idx)
{
	if (img_inf[idx].flags.eventFlag())
	{
		return &img_inf[idx];
	}

	return nullptr;
}

//�ύX���ꂽ������ۑ�
void Controller::changeTxt(const int& idx, String& txt)
{
	txt_inf[idx].txt = txt;
	txt_inf[idx].flags.flag_t = true;
}

//�󕶎���ۑ����邱�ƂŁC�폜�������Ƃɂ���
void Controller::deleteTxt(const int& idx)
{
	txt_inf[idx].txt = U"";
	txt_inf[idx].flags.flag_t = true;
}

//�ύX���ꂽ�����T�C�Y��ۑ�
void Controller::changeTxtSize(const int& idx, const double& size)
{
	txt_inf[idx].size = size;
	txt_inf[idx].flags.flag_s = true;
}

//�ύX���ꂽ�����̕`��J�n�^�C�~���O��ۑ�
void Controller::changeTxtFadein(const int& idx, const double& fadein)
{
	txt_inf[idx].fadein = fadein;
}

//�������̎󂯓n��
TxtInf* Controller::returnTxtInf(const int& idx)
{
	if (txt_inf[idx].flags.eventFlag())
	{
		return &txt_inf[idx];
	}

	return nullptr;
}

//�ҏW��ʂ̋�`�`��ʒu��Ԃ�
Vec2 Controller::returnBasePos()
{
	return base_pos;
}

//�ҏW��ʂ̋�`�`��ʒu��ύX���C�ۑ�
void Controller::changePos(Vec2& base)
{
	base_pos = base;
}

//�摜�╶���̕`��ʒu��ύX���C�ۑ�
void Controller::changePos(const int& idx, Vec2& pos)
{
	if (idx < 3)
	{
		img_inf[idx].pos = pos;
	}
	else
	{
		//�摜���ƕ������̔z�񂪕ʂȂ̂ŁC�Y���������Z�b�g
		auto txt_idx = idx % 3;
		txt_inf[txt_idx].pos = pos;
	}
}

//�R���X�g���N�^�ŌĂ΂�鏉��������
void Controller::init()
{
	base_pos = Vec2::Zero();
	img_inf.clear();
	txt_inf.clear();
	img_inf.resize(3);
	txt_inf.resize(2);
	setInitFlag();
}

//�ύX�t���O��S��true�ɂ���
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

//�t�@�C���ǂݍ��ݎ��̃p�X���쐬
void Controller::makeReadFilePath()
{
	//�ꎞ���t�@�C��������΁C��������ǂݍ���
	makeTempPath();
	if (!FileSystem::Exists(path))
	{
		makeFilePath();
	}
}

//�t�@�C���ǂݍ��ݎ��̃p�X���쐬�C�y�[�W�w�肪�ł���
void Controller::makeReadFilePath(const int& page)
{
	makeTempPath(page);
	if (!FileSystem::Exists(path))
	{
		makeFilePath(page);
	}
}

//�t�@�C���p�X���쐬
void Controller::makeFilePath()
{
	path = U"Page/page{}.json"_fmt(cur_page);
}

//�t�@�C���p�X���쐬�C�y�[�W�w�肪�ł���
void Controller::makeFilePath(const int& page)
{
	path = U"Page/page{}.json"_fmt(page);
}

//�ꎞ���t�@�C���p�X���쐬
void Controller::makeTempPath()
{
	path = U"Page/temp{}.json"_fmt(cur_page);
}

//�ꎞ���t�@�C���p�X���쐬�C�y�[�W�w�肪�ł���
void Controller::makeTempPath(const int& page)
{
	path = U"Page/temp{}.json"_fmt(page);
}

//����JSON�t�@�C���ɏ�������
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

//JSON�t�@�C���ǂݍ���
void Controller::readPageJson()
{
	JSONReader json(path);
	if (!json)
	{
		//�쐬�����t�@�C������؂Ȃ��Ƃ��C�����t�@�C����ǂݍ���
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

//�ꎞ���t�@�C�����폜�C�f�X�g���N�^�ŌĂ΂��(Book�ł͖���)
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