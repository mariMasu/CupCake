//
//  LongMenu.hpp
//  MakingCupcakes
//
//  Created by 枡岡真里 on 2016/05/09.
//
//

#ifndef LongMenu_hpp
#define LongMenu_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class LongMenu :public cocos2d::MenuItemImage
{
    
    
    
public:
    
    float _touchT = 0;
    bool _end = false;
    bool _ended = false;
    
    LongMenu();
    virtual ~LongMenu();
    
    bool init() override;
    
    static LongMenu* create(const std::string&normalImage, const std::string&selectedImage, const ccMenuCallback& callback);

    static LongMenu* create(const std::string&normalImage, const std::string&selectedImage, const std::string&disabledImage, const ccMenuCallback& callback);

    void selected()override;
    virtual void unselected()override;

    void sche(float dt);
    
    CREATE_FUNC(LongMenu);
    
    
};


#endif /* LongMenu_hpp */
