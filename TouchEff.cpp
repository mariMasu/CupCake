//
//  TouchEff.cpp
//  MakingCupcakes
//
//  Created by 枡岡真里 on 2016/05/09.
//
//

#include "TouchEff.hpp"

USING_NS_CC;

TouchEff::TouchEff(){
    
}

TouchEff::~TouchEff(){
    
}

bool TouchEff::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    _setupEventListener();
    
    return true;
}

void TouchEff::_setupEventListener()
{
    //タッチ用イベントリスナーの生成
    auto touchListener = EventListenerTouchOneByOne::create();
    
    //タッチダウンイベント設定
    touchListener->onTouchBegan = CC_CALLBACK_2( TouchEff::onTouchBegan, this );
    
    //生成したイベントリスナーをディスパッチャーへ登録
    _eventDispatcher->addEventListenerWithSceneGraphPriority( touchListener, this );
}

bool TouchEff::onTouchBegan( Touch *touch, Event *event )
{
    ParticleSystemQuad* pSys;
    pSys = ParticleSystemQuad::create("touch.plist");
    pSys->setPosition(touch->getLocation());
    pSys->setAutoRemoveOnFinish(true);
    
    this->addChild(pSys);
    
    return true;
}
