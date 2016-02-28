//
//  ButtonLayer.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#include "ButtonLayer.hpp"

USING_NS_CC;


ButtonLayer::ButtonLayer(){
    
}

ButtonLayer::~ButtonLayer(){
    
}

bool ButtonLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                      [](Ref* ref){
                                          auto scene = CupcakeTitle::createScene();
                                          auto transition = TransitionPageTurn::create(1.5, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                          
                                      });
    
    next->setScale(0.8);
    
    auto nextMenu = Menu::create(next, NULL);
    
    
    nextMenu->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    this->addChild(nextMenu);
    
    
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [](Ref* ref){
                                          auto scene = CupcakeTitle::createScene();
                                          auto transition = TransitionPageTurn::create(1.5, scene,true);
                                          Director::getInstance()->replaceScene(transition);
                                          
                                      });
    
    back->setScale(0.8);
    
    auto backMenu = Menu::create(back, NULL);
    
    
    backMenu->setPosition(Vec2(winSize.width / 2 * 0.2, winSize.height / 1.1));
    
    this->addChild(backMenu);
    
    
    
    return true;
}

Scene* ButtonLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ButtonLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}