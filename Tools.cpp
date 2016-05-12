//
//  Tools.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Tools.hpp"
#include "CupcakeTitle.hpp"

#include "TouchEff.hpp"

#include "audio/include/SimpleAudioEngine.h"

USING_NS_CC;


Tools::Tools(){
    
}

Tools::~Tools(){
    
}

bool Tools::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Tools::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority
    (listener, this);
    
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

void Tools::addTouchEff(Layer *layer){

    auto touchEff = TouchEff::create();
    layer->addChild(touchEff,10);
    
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

cocos2d::Label* Tools::blueLabel(std::string str,int size,bool dark){
    
    cocos2d::Label *label = cocos2d::Label::createWithSystemFont(str, "Marker Felt", size);
    
    if(dark){
        label->setColor(Color3B(0,160,210));
        label->enableOutline(Color4B(0, 160, 210, 255),5);
    }else{
        label->setColor(Color3B(255,255,255));
        label->enableOutline(Color4B(0, 160, 210, 255),5);
    }
    return label;
    
}

void Tools::playSound(enum sound kind){
    
    std::string path;
    bool loop = false;
    
    switch(kind)
    {
        case sound::TAP1:{
            path = "tap1.mp3";
            break;
        }
         
        case sound::TAP2:{
            path = "tap2.mp3";
            break;
        }
        case sound::D1:{
            path = "D1.mp3";
            break;
        }
        case sound::D2:{
            path = "D2.mp3";
            break;
        }
        case sound::D3:{
            path = "D3.mp3";
            break;
        }
        case sound::KIRAKI:{
            path = "kiraki.mp3";
            break;
        }
        case sound::DRUM:{
            path = "drum.mp3";
            break;
        }
        case sound::CYMBAL:{
            path = "symbal.mp3";
            break;
        }
        case sound::CLAP:{
            path = "clap.mp3";
            break;
        }
        case sound::END:{
            path = "end.mp3";
            loop = true;
            break;
        }
        case sound::MILK:{
            path = "milk.mp3";
            break;
        }
        case sound::BUTTER:{
            path = "butter.mp3";
            break;
        }
        case sound::SUGAR:{
            path = "sugar.mp3";
            break;
        }
        case sound::BAKINGP:{
            path = "bakingP.mp3";
            break;
        }
        case sound::FLOUR:{
            path = "flour.mp3";
            break;
        }
        case sound::EGG:{
            path = "egg.mp3";
            break;
        }
            
        case sound::P0:{
            path = "Making_Cup.mp3";
            break;
        }
        case sound::P1:{
            path = "Ingredient.mp3";
            break;
        }
        case sound::P2:{
            path = "Mix_the.mp3";
            break;
        }
        case sound::P3:{
            path = "Add_the.mp3";
            break;
        }
        case sound::P4:{
            path = "Sift_the.mp3";
            break;
        }
        case sound::P5:{
            path = "Bake_for.mp3";
            break;
        }
        case sound::P6a:{
            path = "Decorate!.mp3";
            break;
        }
        case sound::P6b:{
            path = "Congratulations!.mp3";

            break;
        }
    
    
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(path.c_str(),loop);
    
}

void Tools::playSoundSet(int num,std::string kind){
    
    std::string path;
    float volume = 1;
    
    if(num == 3){
        
        int rnd = random(0, 2);
        
        switch (rnd) {
            case 0:
                path = kind + "2.mp3";
                break;
            case 1:
                path = kind + "3.mp3";
                break;
            case 2:
                path = kind + "4.mp3";
                break;
        }
    }else{
        path = kind + "1.mp3";
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(path.c_str());
    
}


void Tools::customAction(cocos2d::Ref *item,int num,Size winSize){
    
    auto actionItem = static_cast<Node*>(item);
    
    if(actionItem->getNumberOfRunningActions()==0){
        if(num == 1){
            
            auto action1 = RotateBy::create(0.2, -15);
            auto action2 = RotateBy::create(0.2, 30);
            auto action3 = RotateBy::create(0.2, -15);
            
            auto actions = Sequence::create(action1,action2,action3, NULL);
            
            actionItem->runAction(actions);
            
        }else if(num == 2){
            
            auto randMinus = [](int num){
                float rnum = num;
                if(random(0, 1)){
                    rnum *= -1;
                }
                return rnum;
            };
            
            int max = winSize.width/1.5;
            auto x = random(0,max);
            auto y = winSize.height*1.5;
            auto point = Vec2(randMinus(x), randMinus(y));
            
            auto action1 = MoveBy::create(0.4, point);
            auto action2 = RotateBy::create(0.4,360);
            auto actions = Spawn::create(action1, action2, NULL);
            
            actionItem->runAction(actions);
            
        }else if(num == 3){
            
            auto action1 = RotateTo::create(0.8, -5);
            auto action2 = RotateTo::create(0.8, 0);
            auto action3 = RotateTo::create(0.8, 5);
            auto action4 = RotateTo::create(0.8, 0);
            
            auto actions = Sequence::create(action1,action2,action3,action4, NULL);
            
            auto repeat = RepeatForever::create(actions);
            actionItem->runAction(repeat);
        }
    }
    
}


