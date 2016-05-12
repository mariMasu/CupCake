//
//  TouchEff.hpp
//  MakingCupcakes
//
//  Created by 枡岡真里 on 2016/05/09.
//
//

#ifndef TouchEff_hpp
#define TouchEff_hpp

#include <stdio.h>

USING_NS_CC;

class TouchEff : public Layer
{
public:
    
    TouchEff();
    virtual ~TouchEff();
    CREATE_FUNC(TouchEff);
    virtual bool init();
    
    void close();
    //タッチ・ダウン処理
    virtual bool onTouchBegan( Touch* touch, Event* event );
    
protected:
    
    //タッチイベント登録
    void _setupEventListener();
};


#endif /* TouchEff_hpp */
