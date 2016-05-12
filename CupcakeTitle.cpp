//
//  CupcakeTitle.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#include "CupcakeTitle.hpp"
#include <Page1.hpp>

#include "Tools.hpp"


USING_NS_CC;


CupcakeTitle::CupcakeTitle(){
    
}

CupcakeTitle::~CupcakeTitle(){
    
}

bool CupcakeTitle::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto winSize = Director::getInstance()->getWinSize();
    
    auto tools = Tools::create();
    tools->addTouchEff(this);
    tools->addBackGround(this);
    
    auto titleFrame = Sprite::create("CupcakeFrame.png");
    titleFrame->setScale(0.8, 0.6);
    titleFrame->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.7));
    this->addChild(titleFrame);
    
    
    auto titleLabel = tools->blueLabel("カップケーキを作ろう！", 70,true);
    
    auto titleButton = MenuItemLabel::create(titleLabel,
                                             [&](Ref* ref){
                                                 
                                                 auto label = static_cast<MenuItemLabel*>(ref);
                                                 label->setString("Making Cupcakes");
                                                 label->setScale(1.5);
                                                 
                                                 tools->playSound(Tools::sound::P0);
                                             });
    
    auto titleLabelMenu = Menu::create(titleButton,NULL);
    titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.7));
    this->addChild(titleLabelMenu, 2);

    
    auto start = MenuItemImage::create("CupcakeStart.png","CupcakeStartPress.png",
                                       [&](Ref* ref){
                                           auto scene = Page1::createScene();
                                           tools->playSound(Tools::sound::TAP1);
                                           auto transition = TransitionPageTurn::create(1.5, scene,false);
                                           Director::getInstance()->replaceScene(transition);
                                           
    });
    
    
    auto menu = Menu::create(start, NULL);
    
    
    menu->setPosition(Vec2(winSize.width / 2, winSize.height / 4));
    
    this->addChild(menu);
    
    
    return true;
}


Scene* CupcakeTitle::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CupcakeTitle::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}