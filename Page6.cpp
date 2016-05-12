//
//  Page6.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Page6.hpp"

#include "CupcakeTitle.hpp"
#include "Page5.hpp"
#include "Tools.hpp"
#include "audio/include/SimpleAudioEngine.h"


USING_NS_CC;


Page6::Page6(){
    
}

Page6::~Page6(){
    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
    _photo2->stopAllActions();
    _longMenu->stopAllActions();
}

bool Page6::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    tools->addTouchEff(this);
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    auto titleLabel = tools->blueLabel("かざりつけ！", 50,true);
    
    auto titleButton = MenuItemLabel::create(titleLabel,
                                             [&](Ref* ref){
                                                 
                                                 auto label = static_cast<MenuItemLabel*>(ref);
                                                 label->setString("Decorate!");
                                                 label->setScale(1.2);
                                                 
                                                 tools->playSound(Tools::sound::P6a);
                                             });
    
    auto titleLabelMenu = Menu::create(titleButton,NULL);
    titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    titleLabelMenu->setTag(10);
    this->addChild(titleLabelMenu, 2);
    
    
    auto photo2 = MenuItemImage::create("CupcakeMake9.png","CupcakeMake9.png",
                                        [&](Ref* ref){
                                            
                                            tools->playSound(Tools::sound::CLAP);
                                            auto winS = Director::getInstance()->getWinSize();
                                            
                                            ParticleSystemQuad* pSys;
                                            pSys = ParticleSystemQuad::create("kirakira.plist");
                                            pSys->setPosition(Vec2(winS.width / 2.0, winS.height / 2));
                                            pSys->setAutoRemoveOnFinish(true);
                                            
                                            this->addChild(pSys);
                                           
                                       });
    
    photo2->setScale(1.3);
    photo2->setPosition(Vec2(winSize.width * 2, winSize.height * 2));
    photo2->setTag(222);
    
    auto photo1 = LongMenu::create("CupcakeMake8.png","CupcakeMake8.png",
                                       [&](Ref* ref){
                                           });
    
    
    photo1->setScale(1.3);
    photo1->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    photo1->setTag(111);
    
    auto photoMenu = Menu::create(photo2,photo1,NULL);
    photoMenu->setPosition(0,0);
    this->addChild(photoMenu);
    _longMenu = static_cast<LongMenu*>(photoMenu->getChildByTag(111));
    _photo2 = static_cast<MenuItemImage*>(photoMenu->getChildByTag(222));
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);
                                          auto scene = Page5::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,true);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    back->setScale(0.8);
    back->setPosition(Vec2(winSize.width / 2 * 0.2, winSize.height / 1.1));
    
    
    auto Button = Menu::create(back, NULL);
    Button->setPosition(0, 0);
    this->addChild(Button);
    
    this->schedule(schedule_selector(Page6::endSche),0.1);
    
    return true;
}

Scene* Page6::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page6::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

void Page6::endSche(float dt){
    
    if(_longMenu->_end && _longMenu->_ended != true){
        
        auto winSize = Director::getInstance()->getWinSize();
        auto tools = Tools::create();

        _photo2->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));

        tools->playSound(Tools::sound::END);
        tools->customAction(_photo2, 3);
        
        this->removeChildByTag(10);
        
        auto titleLabel = tools->blueLabel("おめでとう！", 50,true);
        auto titleButton = MenuItemLabel::create(titleLabel,
                                                 [&](Ref* ref){
                                                     
                                                     auto label = static_cast<MenuItemLabel*>(ref);
                                                     label->setString("Congratulations!");
                                                     label->setScale(1.2);
                                                     
                                                     tools->playSound(Tools::sound::P6b);
                                                 });
        
        auto titleLabelMenu = Menu::create(titleButton,NULL);
        titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
        titleLabelMenu->setTag(10);
        this->addChild(titleLabelMenu, 2);
        
        auto toTitle = MenuItemImage::create("CupcakeTitle.png","CupcakeTitlePress.png",
                                           [&](Ref* ref){
                                               tools->playSound(Tools::sound::TAP1);

                                               auto scene = CupcakeTitle::createScene();
                                               auto transition = TransitionPageTurn::create(1.2, scene,false);
                                               Director::getInstance()->replaceScene(transition);
                                           });
        toTitle->setScale(0.8);
        toTitle->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
        auto toTitleButton = Menu::create(toTitle,NULL);
        toTitleButton->setPosition(0, 0);
        this->addChild(toTitleButton);
        
        _longMenu->_ended  = true;
    }
    
}