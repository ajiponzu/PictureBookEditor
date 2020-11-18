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
	cur_page++;
	max_page++;
	read_flag = true;
}

void Controller::deletePage()
{
	cur_page--;
	max_page--;
	if (cur_page <= 0)
	{
		cur_page = 1;
	}
	if (max_page <= 0)
	{
		max_page = 1;
	}
	init();
	writePageJson();
	read_flag = true;
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
		read_flag = true;
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
		read_flag = true;
	}
}

void Controller::writePageJson()
{
	String path = U"Page/page{}.json"_fmt(cur_page);
	JSONWriter writer;
	writer.startObject();
	{
		writer.key(U"MaxPage").write(max_page);
		writer.key(U"Image").startObject();
		{
			writer.key(U"img1").startObject();
			{
				writer.key(U"size").write(img_inf[0].size);
				writer.key(U"alpha").write(img_inf[0].alpha);
				writer.key(U"fadein").write(img_inf[0].fadein);
				writer.key(U"path").write(img_inf[0].path);
			}
			writer.endObject();
			writer.key(U"img2").startObject();
			{
				writer.key(U"size").write(img_inf[1].size);
				writer.key(U"alpha").write(img_inf[1].alpha);
				writer.key(U"fadein").write(img_inf[1].fadein);
				writer.key(U"path").write(img_inf[1].path);
			}
			writer.endObject();
			writer.key(U"img3").startObject();
			{
				writer.key(U"size").write(img_inf[2].size);
				writer.key(U"alpha").write(img_inf[2].alpha);
				writer.key(U"fadein").write(img_inf[2].fadein);
				writer.key(U"path").write(img_inf[2].path);
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
			}
			writer.endObject();
			writer.key(U"txt2").startObject();
			{
				writer.key(U"size").write(txt_inf[1].size);
				writer.key(U"fadein").write(txt_inf[1].fadein);
				writer.key(U"txt").write(txt_inf[1].txt);
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
	String path = U"page{}.json"_fmt(cur_page);
    JSONReader json(path);
	if (!json)
    {
		json = JSONReader(U"initialize.json");
    }
	
	for (const auto& inf : json.objectView())
	{
		max_page = inf.value[U"MaxPage"].get<int>();
		for (const auto& sub_inf : inf.value[U"Image"].objectView())
		{
			auto idx = 0;
			for (const auto& sub_sub_inf : sub_inf.value.objectView())
			{
				img_inf[idx].size = sub_sub_inf.value[U"size"].get<double>();
				img_inf[idx].alpha = sub_sub_inf.value[U"alpha"].get<double>();
				img_inf[idx].fadein = sub_sub_inf.value[U"fadein"].get<double>();
				img_inf[idx].path = sub_sub_inf.value[U"path"].getString();
				idx++;
			}
		}
		for (const auto& sub_inf : inf.value[U"Scenario"].objectView())
		{
			auto idx = 0;
			for (const auto& sub_sub_inf : sub_inf.value.objectView())
			{
				txt_inf[idx].size = sub_sub_inf.value[U"size"].get<double>();
				txt_inf[idx].fadein = sub_sub_inf.value[U"fadein"].get<double>();
				txt_inf[idx].txt = sub_sub_inf.value[U"txt"].getString();
				idx++;
			}
		}
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

void Controller::init()
{
	img_inf.clear();
	txt_inf.clear();
	img_inf.resize(3);
	txt_inf.resize(2);
}

