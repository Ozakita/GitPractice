#include "DxLib.h"
#include "Screen.h"
#include "Game.h"

// �ݒ��ʂ́y�����J�[�z���y�V�X�e���z�́y�T�u�V�X�e���z��Windows(SUBSYSTEM:WINDOWS)�ɐݒ肷���WinMain����v���O�������J�n����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ��ʃ��[�h�̐ݒ�
    SetGraphMode(Screen::Width, Screen::Height, 32);  // ��ʃT�C�Y960�~540�̃J���[�r�b�g��32�r�b�g�ŋN��
    SetWindowSize(Screen::Width, Screen::Height);     // �E�B���h�E�T�C�Y960�~540(������SetGraphMode�̃T�C�Y���قȂ�Ɖ摜���䂪��)
    ChangeWindowMode(TRUE);                           //�t���X�N���[���\�����E�B���h�E�\����
    SetMouseDispFlag(TRUE);                           // ������FALSE�ɂ���ƃ}�E�X�J�[�\����\��
    SetMainWindowText("Action");                      //���̍s�ŃG���[�ɂȂ�����y�ݒ�z�}���`�o�C�g�����Z�b�g���Ԉ���Ă邩��
    //�������܂ł̐ݒ�́�����DX���C�u��������������ɂ��Ȃ���DxLib_Init()���͉�ʂ��t���X�N���[���ɂȂ��ďI����Ă���E�B���h�E�T�C�Y���ύX�ɂȂ茩�ꂵ��

    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    Game game;
    game.Init();

    ScreenFlip();

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        game.Update();

        game.Draw();

        ScreenFlip();
    }

    // �L�[���͑҂�������
    WaitKey();
    // �c�w���C�u�����̌�n��
    DxLib_End();
    // �\�t�g�̏I��
    return 0;
}