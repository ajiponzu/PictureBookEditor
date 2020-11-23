#include "BookController.h"

//�y�[�W�J�ڂ��s���邩
bool BookController::isTransition()
{
	return is_transition;
}

//�I���̃y�[�W�Ŏ��y�[�W�J�ڂ��s�������C�܂�I�����邩
bool BookController::isEnd()
{
	return is_end;
}

//�y�[�W�J�ڃt���O��false��
void BookController::resetIsTransition()
{
	is_transition = false;
}

//�I���t���O��false��
void BookController::resetIsEnd()
{
	is_end = false;
}

//�t�@�C���ǂݍ���
void BookController::readPage()
{
	makeReadFilePath2();
	readPageJson();
}

//�O�y�[�W��
void BookController::prevPage()
{
	cur_page--;
	//�s���ȃy�[�W�ԍ��Ȃ�
	if (cur_page <= 0)
	{
		//�J�ږ���
		cur_page = 1;
	}
	else
	{
		//�t�@�C���ǂݍ���
		makeReadFilePath2();
		readPageJson();
		is_transition = true;
	}
}

//���y�[�W��
void BookController::nextPage()
{
	cur_page++;
	//���y�[�W���ȏ�Ȃ�
	if (cur_page > max_page)
	{
		//�J�ږ���
		cur_page--;
		is_end = true;
	}
	else
	{
		//�t�@�C���ǂݍ���
		makeReadFilePath2();
		readPageJson();
		is_transition = true;
	}
}

//�t�@�C���p�X�쐬
void BookController::makeReadFilePath2()
{
	//�ꎞ�t�@�C������������C��������ǂݍ���
	makeTempPath2();
	if (!FileSystem::Exists(path))
	{
		makeFilePath2();
	}
}

void BookController::makeFilePath2()
{
	path = U"page{}.json"_fmt(cur_page);
}

void BookController::makeTempPath2()
{
	path = U"temp{}.json"_fmt(cur_page);
}

//�摜����Ԃ�
Array<ImgInf> BookController::returnImgInfArray()
{
	return img_inf;
}

//��������Ԃ�
Array<TxtInf> BookController::returnTxtInfArray()
{
	return txt_inf;
}