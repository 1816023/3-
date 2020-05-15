#include<DxLib.h>
#include<vector>
#include <time.h>
#include "sceneMng.h"
// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(1230, 960, 16);		// �𑜓x��640*480�Acolor��16bit�ɐݒ�.
	ChangeWindowMode(TRUE);			// �E�C���h�E���[�h��.

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	srand(time(NULL));

	sceneMng* scene = new sceneMng();
	scene->Iint();

	while (1)
	{
		scene->main();
		

	
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0)
		{
			break;
		}
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	return 0;
}