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
    // *ポインタ撲滅運動 PlayScene* playScene;
    int imageWidth = 0;
    int imageHeight = 0;
    int hitboxOffsetLeft = 0;
    int hitboxOffsetRight = 0;
    int hitboxOffsetTop = 0;
    int hitboxOffsetBottom = 0;

public:
    // 1フレーム前
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

    // 当たり判定の左端を取得
    virtual float GetLeft()
    {
        return x + hitboxOffsetLeft;
    }

    // 左端を指定することにより位置を設定する
    virtual void SetLeft(float left)
    {
        x = left - hitboxOffsetLeft;
    }

    // 右端を取得
    virtual float GetRight()
    {
        return x + imageWidth - hitboxOffsetRight;
    }

    // 右端を指定することにより位置を設定する
    virtual void SetRight(float right)
    {
        x = right + hitboxOffsetRight - imageWidth;
    }

    // 上端を取得
    virtual float GetTop()
    {
        return y + hitboxOffsetTop;
    }

    // 上端を指定することにより位置を設定する
    virtual void SetTop(float top)
    {
        y = top - hitboxOffsetTop;
    }

    // 下端を取得する
    virtual float GetBottom()
    {
        return y + imageHeight - hitboxOffsetBottom;
    }

    // 下端を指定することにより位置を設定する
    virtual void SetBottom(float bottom)
    {
        y = bottom + hitboxOffsetBottom - imageHeight;
    }

    // 1フレーム前からの移動量（x方向）
    float GetDeltaX()
    {
        return x - prevX;
    }

    // 1フレーム前からの移動量（y方向）
    float GetDeltaY()
    {
        return y - prevY;
    }

    // 1フレーム前の左端を取得する
    float GetPrevLeft()
    {
        return prevLeft;
    }

    // 1フレーム前の右端を取得する
    float GetPrevRight()
    {
        return prevRight;
    }

    // 1フレーム前の上端を取得する
    float GetPrevTop()
    {
        return prevTop;
    }

    // 1フレーム前の下端を取得する
    float GetPrevBottom()
    {
        return prevBottom;
    }

    // 1フレーム前の場所と当たり判定を記憶する
    void StorePositionAndHitBox()
    {
        prevX = x;
        prevY = y;
        prevLeft = GetLeft();
        prevRight = GetRight();
        prevTop = GetTop();
        prevBottom = GetBottom();
    }

    // 更新処理
    virtual void Update() = 0;

    // 描画処理
    virtual void Draw() = 0;

    // 当たり判定を描画（デバッグ用）
    void DrawHitBox()
    {
        //四角形を描画
        DrawBox(
            (int)(GetLeft() + 0.5f),    // 左端
            (int)(GetTop() + 0.5f),     // 上端
            (int)(GetRight() + 0.5f),   // 右端
            (int)(GetBottom() + 0.5f),  // 下端
            GetColor(255, 0, 0),     // 色
            FALSE);                  // TRUE:塗りつぶし, FALSE:枠線のみ

        Camera::DrawLineBox(GetLeft(), GetTop(), GetRight(), GetBottom(), GetColor(255, 0, 0));
    }

    // 他のオブジェクトと衝突したときに呼ばれる
    virtual void OnCollision(std::shared_ptr<GameObject> other) = 0;

    // 画面内に映っているか？
    virtual bool IsVisible()
    {
        return MyMath::RectRectIntersect(
            x, y, x + imageWidth, y + imageHeight,
            Camera::x, Camera::y, Camera::x + Screen::Width, Camera::y + Screen::Height);
    }
};

#endif