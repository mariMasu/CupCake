//
//  Tools.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Tools.hpp"
#include "CupcakeTitle.hpp"
#include "Page1.hpp"
#include "Page2.hpp"


USING_NS_CC;


Tools::Tools(){
    
}

Tools::~Tools(){
    
}

bool Tools::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    _winSize = Director::getInstance()->getWinSize();
    
    return true;
}


void Tools::addBackGround(Layer *layer){
    
    auto background = Sprite::create("CupcakeBackground.png");
    background->setPosition(Vec2(_winSize.width / 2.0, _winSize.height / 2.0));
    layer->addChild(background);
    
    
}

void Tools::addTitleFrame(Layer *layer){
    

    auto titleFrame = Sprite::create("CupcakeFrame.png");
    titleFrame->setScale(0.5, 0.3);
    titleFrame->setPosition(Vec2(_winSize.width / 2.0, _winSize.height / 1.1));
    layer->addChild(titleFrame);
    
    
    
}

void Tools::addNext(Layer *layer,int tag){
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png");
    next->setScale(0.8);
    next->setPosition(Vec2(_winSize.width / 2 * 1.8, _winSize.height / 1.1));
    
    auto Button = Menu::create(next,NULL);
    Button->setPosition(0, 0);
    Button->setTag(tag);
    layer->addChild(Button);
    
}
                                      
void Tools::addBack(Layer *layer,int tag){
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png");
    back->setScale(0.8);
    back->setPosition(Vec2(_winSize.width / 2 * 0.2, _winSize.height / 1.1));
    
    auto Button = Menu::create(back,NULL);
    Button->setPosition(0, 0);
    Button->setTag(tag);

    layer->addChild(Button);
    
}

cocos2d::Scene* Tools::createNextBackScean(int swi){
    switch (swi) {
            
        case 0:
            return CupcakeTitle::createScene();
            break;
            
        case 1:
            return Page1::createScene();
            break;
            
        case 2:
            return Page2::createScene();
            break;
            
        case 3:
            return Page2::createScene();
            break;
            
        default:
            return nullptr;
            break;
    }
}


