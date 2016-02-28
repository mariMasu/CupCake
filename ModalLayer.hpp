//
//  ModalLayer.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#ifndef ModalLayer_hpp
#define ModalLayer_hpp

#include <stdio.h>

USING_NS_CC;

class ModalWindow : public Layer
{
public:
    
    static ModalWindow *create();
    virtual bool init();
    
    //ダイアログ削除処理
    void close();
    //タッチ・ダウン処理
    virtual bool onTouchBegan( Touch* touch, Event* event );
    //タッチ・リリース処理
    virtual void onTouchEnded( Touch* touch, Event* event );
    
protected:
    //ダイアログ背景用Node
    Node *_background;
    //ダイアログ外の透過カラーレイヤー
    LayerColor *_colorSheet;
    
    //タッチイベント登録
    void _setupEventListener();
};

#endif /* ModalLayer_hpp */
