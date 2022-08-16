//
//  SARUnArchiveANY.h
//  SARUnArchiveANY
//
//  Created by Saravanan V on 26/04/13.
//  Copyright (c) 2013 SARAVANAN. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SSZipArchive.h"
#import <SSZipArchive/SSZipArchive.h>
#import <LzmaSDK_ObjC/LzmaSDKObjC.h>
#define UNIQUE_KEY( x ) NSString * const x = @#x

enum{
    SARFileTypeZIP,
    SARFileTypeRAR
};

static UNIQUE_KEY( rar );
static UNIQUE_KEY( zip );

typedef void(^Completion)(NSArray *filePaths);
typedef void(^Failure)();
typedef void(^Progress)(unsigned long long loaded, unsigned long long total);
typedef void(^Decompress7zProgress)(float progress);

@interface SARUnArchiveANY : NSObject <SSZipArchiveDelegate, LzmaSDKObjCReaderDelegate>{
    SSZipArchive *_zipArchive;
    NSString *_fileType;
    LzmaSDKObjCReader *_reader;
}

@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *destinationPath;
@property (nonatomic, copy) Completion completionBlock;
@property (nonatomic, copy) Failure failureBlock;
@property (nonatomic, copy) Decompress7zProgress progress7zBlock;

- (id)initWithPath:(NSString *)path;
- (void)decompress;

@end
