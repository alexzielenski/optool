optool
======

optool is a tool which interfaces with MachO binaries in order to insert/remove load commands, strip code signatures, resign, and remove aslr. Below is its help.

```
optool v0.1

USAGE:
  install -c <command> -p <payload> -t <target> [-o=<output>] [-b] [--resign] In
  serts an LC_LOAD command into the target binary which points to the payload. T
  his may render some executables unusable.

  uninstall -p <payload> -t <target> [-o=<output>] [-b] [--resign] Removes any L
  C_LOAD commands which point to a given payload from the target binary. This ma
  y render some executables unusable.

  strip [-w] -t <target> Removes a code signature load command from the given bi
  nary.

  restore -t <target> Restores any backup made on the target by this tool.

  aslr -t <target> [-o=<output>] [-b] [--resign] Removes an ASLR flag from the m
  acho header if it exists. This may render some executables unusable


OPTIONS:
  [-w --weak] Used with the STRIP command to weakly remove the signature. Withou
  t this, the code signature is replaced with null bytes on the binary and its L
  OAD command is removed.

  [--resign] Try to repair the code signature after any operations are done. Thi
  s may render some executables unusable.

  -t|--target <target> Required of all commands to specify the target executable
   to modify

  -p|--payload <payload> Required of the INSTALL and UNINSTALL commands to speci
  fy the path to a DYLIB to point the LOAD command to

  [-c --command] Specify which type of load command to use in INSTALL. Can be re
  export for LC_REEXPORT_DYLIB, weak for LC_LOAD_WEAK_DYLIB, upward for LC_LOAD_
  UPWARD_DYLIB, or load for LC_LOAD_DYLIB

  [-b --backup] Backup the executable to a suffixed path (in the form of _backup
  .BUNDLEVERSION)

  [-h --help] Show this message


(C) 2014 Alexander S. Zielenski. Licensed under BSD
```

License
===

optool is licensed under BSD. Below is the license reproduced in its entirety:

```
Copyright (c) 2014, Alex Zielenski
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

