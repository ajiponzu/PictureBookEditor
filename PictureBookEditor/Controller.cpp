#include "Controller.h"

int Controller::returnCurrentPage()
{
	return cur_page;
}

int Controller::returnMaxPage()
{
	return max_page;
}

void Controller::createPage()
{
	writePageJson();
	cur_page++;
	max_page++;
	init();
}

void Controller::deletePage()
{
	String path = U"Page/page{}.json"_fmt(cur_page);
	max_page--;
	if (max_page <= 0)
	{
		max_page = 1;
	}
	FileSystem::Remove(path, true);

	cur_page--;
	if (cur_page <= 0)
	{
		cur_page = 2;
		readPageJson();
		path = U"Page/page{}.json"_fmt(cur_page);
		FileSystem::Remove(path, true);
		cur_page = 1;
		writePageJson();
	}
	else
	{
		readPageJson();
	}
}

void Controller::nextPage()
{
	if (cur_page != max_page)
	{
		writePageJson();
	}
	cur_page++;
	if (cur_page > max_page)
	{
		cur_page = max_page;
	}
	else
	{
		readPageJson();
	}
}

void Controller::prevPage()
{
	if (cur_page != 1)
	{
		writePageJson();
	}
	cur_page--;
	if (cur_page <= 0)
	{
		cur_page = 1;
	}
	else
	{
		readPageJson();
	}
}

void Controller::writePageJson()
{
	String path = U"Page/page{}.json"_fmt(cur_page);
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
	String path = U"Page/page{}.json"_fmt(cur_page);
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

void Controller::changePos(Vec2&)
{
}

void Controller::changePos(const int&, Vec2&)
{
}


void Controller::init()
{
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