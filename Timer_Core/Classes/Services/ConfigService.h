//
//  ConfigService.h
//  Timer_Core
//
//  Created by myuon on 2014/11/30.
//  Copyright (c) 2014年 yasu. All rights reserved.
//

#ifndef __Timer_Core__ConfigService__
#define __Timer_Core__ConfigService__

#include <stdio.h>

#include <string>

class ConfigService {
private:
    ConfigService() {}

public:
//    const char *ConfigFilePath = "~/.timerC.d";
    static const char *DefaultStorageDirectory;
    static const char *SavedTimerFileName;

    /*! @abstract タイマーの保存先のパスを取得する
     @return パスの文字数を返却する
     */
    static void getSavedTimerPath(std::string &path);

};

#endif /* defined(__Timer_Core__ConfigService__) */
