//
//  Tools.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#ifndef Tools_hpp
#define Tools_hpp

#include <stdio.h>

#include "cocos2d.h"

class Tools : public cocos2d::Layer
{
public:
    
    cocos2d::Size _winSize;
    
    enum class sound
    {
        TAP1,
        TAP2,
        D1,
        D2,
        D3,
        KIRAKI,
        DRUM,
        CYMBAL,
        END,
        CLAP,
        MILK,
        BUTTER,
        SUGAR,
        BAKINGP,
        FLOUR,
        EGG,
        P0,
        P1,
        P2,
        P3,
        P4,
        P5,
        P6a,
        P6b
        
    };
    Tools();
    
    virtual ~Tools();
    
    virtual bool init();
    
    CREATE_FUNC(Tools);
    
    void addBackGround(Layer *layer);
    
    void addTitleFrame(Layer *layer);
    
    void addTouchEff(Layer *layer);
    
    void addNext(Layer *layer,int tag);
    
    void addBack(Layer *layer,int tag);
    
    cocos2d::Label *blueLabel(std::string str,int size,bool dark);
    
    void playSound(enum sound kind);
    
    void playSoundSet(int num,std::string kind);
    void customAction(cocos2d::Ref *item,int nam,cocos2d::Size winSize = cocos2d::Size(0, 0));
    
};


#endif /* Tools_hpp */
