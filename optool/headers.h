//
//  headers.h
//  Opee
//
//  Created by Alexander S Zielenski on 7/22/14.
//  Copyright (c) 2014 Alex Zielenski. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "defines.h"

struct thin_header headerAtOffset(NSData *binary, uint32_t offset);
struct thin_header *headersFromBinary(struct thin_header *headers, NSData *binary, uint32_t *amount);