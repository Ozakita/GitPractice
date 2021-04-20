#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>
#include <memory>
#include "GameManager.h"
#include "PlayScene.h"
#include "Camera.h"
#include "MyMath.h"

class GameObject
{
public:
    GameManager& gm = GameManager::GetInstance();

    std::string tag = "";

    float x;
    float y;
    bool isDead = false;

protected:
    // *�|�C���^�o�ŉ^�� PlayScene* playScene;
    int imageWidth = 0;
    int imageHeight = 0;
    int hitboxOffsetLeft = 0;
    int hitboxOffsetRight = 0;
    int hitboxOffsetTop = 0;
    int hitboxOffsetBottom = 0;

public:
    // 1�t���[���O
    float prevX;
    float prevY;
    float prevLeft;
    float prevRight;
    float prevTop;
    float prevBottom;

    GameObject()
    {
    }

    virtual ~GameObject()
    {

    }

    // �����蔻��̍��[���擾
    virtual float GetLeft()
    {
        return x + hitboxOffsetLeft;
    }

    // ���[���w�肷�邱�Ƃɂ��ʒu��ݒ肷��
    virtual void SetLeft(float left)
    {
        x = left - hitboxOffsetLeft;
    }

    // �E�[���擾
    virtual float GetRight()
    {
        return x + imageWidth - hitboxOffsetRight;
    }

    // �E�[���w�肷�邱�Ƃɂ��ʒu��ݒ肷��
    virtual void SetRight(float right)
    {
        x = right + hitboxOffsetRight - imageWidth;
    }

    // ��[���擾
    virtual float GetTop()
    {
        return y + hitboxOffsetTop;
    }

    // ��[���w�肷�邱�Ƃɂ��ʒu��ݒ肷��
    virtual void SetTop(float top)
    {
        y = top - hitboxOffsetTop;
    }

    // ���[���擾����
    virtual float GetBottom()
    {
        return y + imageHeight - hitboxOffsetBottom;
    }

    // ���[���w�肷�邱�Ƃɂ��ʒu��ݒ肷��
    virtual void SetBottom(float bottom)
    {
        y = bottom + hitboxOffsetBottom - imageHeight;
    }

    // 1�t���[���O����̈ړ��ʁix�����j
    float GetDeltaX()
    {
        return x - prevX;
    }

    // 1�t���[���O����̈ړ��ʁiy�����j
    float GetDeltaY()
    {
        return y - prevY;
    }

    // 1�t���[���O�̍��[���擾����
    float GetPrevLeft()
    {
        return prevLeft;
    }

    // 1�t���[���O�̉E�[���擾����
    float GetPrevRight()
    {
        return prevRight;
    }

    // 1�t���[���O�̏�[���擾����
    float GetPrevTop()
    {
        return prevTop;
    }

    // 1�t���[���O�̉��[���擾����
    float GetPrevBottom()
    {
        return prevBottom;
    }

    // 1�t���[���O�̏ꏊ�Ɠ����蔻����L������
    void StorePositionAndHitBox()
    {
        prevX = x;
        prevY = y;
        prevLeft = GetLeft();
        prevRight = GetRight();
        prevTop = GetTop();
        prevBottom = GetBottom();
    }

    // �X�V����
    virtual void Update() = 0;

    // �`�揈��
    virtual void Draw() = 0;

    // �����蔻���`��i�f�o�b�O�p�j
    void DrawHitBox()
    {
        //�l�p�`��`��
        DrawBox(
            (int)(GetLeft() + 0.5f),    // ���[
            (int)(GetTop() + 0.5f),     // ��[
            (int)(GetRight() + 0.5f),   // �E�[
            (int)(GetBottom() + 0.5f),  // ���[
            GetColor(255, 0, 0),     // �F
            FALSE);                  // TRUE:�h��Ԃ�, FALSE:�g���̂�

        Camera::DrawLineBox(GetLeft(), GetTop(), GetRight(), GetBottom(), GetColor(255, 0, 0));
    }

    // ���̃I�u�W�F�N�g�ƏՓ˂����Ƃ��ɌĂ΂��
    virtual void OnCollision(std::shared_ptr<GameObject> other) = 0;

    // ��ʓ��ɉf���Ă��邩�H
    virtual bool IsVisible()
    {
        return MyMath::RectRectIntersect(
            x, y, x + imageWidth, y + imageHeight,
            Camera::x, Camera::y, Camera::x + Screen::Width, Camera::y + Screen::Height);
    }
};

#endif