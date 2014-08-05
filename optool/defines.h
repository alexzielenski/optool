//
//  defines.h
//  Opee
//
//  Created by Alexander S Zielenski on 7/22/14.
//  Copyright (c) 2014 Alex Zielenski. All rights reserved.
//

#import <mach-o/loader.h>

#define LOG(fmt, args...) printf(fmt "\n", ##args)
#define CPU(CPUTYPE) CPUTYPE == CPU_TYPE_I386 ? "x86" : "x86_64"
#define LC(LOADCOMMAND) ({ \
    const char *c = ""; \
    if (LOADCOMMAND == LC_REEXPORT_DYLIB) \
        c = "LC_REEXPORT_DYLIB";\
    else if (LOADCOMMAND == LC_LOAD_WEAK_DYLIB) \
        c = "LC_LOAD_WEAK_DYLIB";\
    else if (LOADCOMMAND == LC_LOAD_UPWARD_DYLIB) \
        c = "LC_LOAD_UPWARD_DYLIB";\
    else if (LOADCOMMAND == LC_LOAD_DYLIB) \
        c = "LC_LOAD_DYLIB";\
    c;\
})

#define COMMAND(str) ({ \
    uint32_t cmd = -1; \
    if ([str isEqualToString: @"reexport"]) \
        cmd = LC_REEXPORT_DYLIB; \
    else if ([str isEqualToString: @"weak"]) \
        cmd = LC_LOAD_WEAK_DYLIB; \
    else if ([str isEqualToString: @"upward"]) \
        cmd = LC_LOAD_UPWARD_DYLIB; \
    else if ([str isEqualToString: @"load"]) \
        cmd = LC_LOAD_DYLIB; \
    cmd; \
})

// we pass around this header which includes some extra information
// and a 32-bit header which we used for both 32-bit and 64-bit files
// since the 64-bit just adds an extra field to the end which we don't need
struct thin_header {
    uint32_t offset;
    uint32_t size;
    struct mach_header header;
};

typedef NS_ENUM(int, OPError) {
    OPErrorNone               = 0,
    OPErrorRead               = 1,           // failed to read target path
    OPErrorIncompatibleBinary = 2,           // couldn't find x86 or x86_64 architecture in binary
    OPErrorStripFailure       = 3,           // failed to strip codesignature
    OPErrorWriteFailure       = 4,           // failed to write data to final output path
    OPErrorNoBackup           = 5,           // no backup to restore
    OPErrorRemovalFailure     = 6,           // failed to remove executable during restore
    OPErrorMoveFailure        = 7,           // failed to move backup to correct location
    OPErrorNoEntries          = 8,           // cant remove dylib entries because they dont exist
    OPErrorInsertFailure      = 9,           // failed to insert load command
    OPErrorInvalidLoadCommand = 10,          // user provided an unnacceptable load command string
    OPErrorResignFailure      = 11,          // codesign failed for some reason
    OPErrorBackupFailure      = 12,          // failed to write backup
    OPErrorInvalidArguments   = 13           // bad arguments
};