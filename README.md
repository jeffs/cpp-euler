The first time you want to run everything, do the following

    . etc/profile   # Configure your shell to locate `bake` et al.
    cd src          # Go to the source code directory.
    bake            # Generate Makefile.
    make -j         # Build the solutions concurrently.
    make test       # Run the test suite.

Whenever you start a new shell to work on this project, source `etc/profile` once.  
Whenever you add files or local includes, run `bake` to regenerate the Makefile.  
Whenever you change code, run `make` to build it.  
To run the test suite, run `make test`.  
To run a particular test, enter its test number at the shell.  For example, to run test 1, just enter `1`.  
To blow away build artifacts, `make clean`.  

See the [`doc`][] directory for build system details.

Except where otherwise noted, the content of this repository is Copyright Unbuggy Software, LLC, 2014, and is distributed under the Boost Software License, Version 1.0.  See the accompanying file [`LICENSE_1_0.txt`][] or the copy at [`http://www.boost.org/LICENSE_1_0.txt`][].

[`doc`]: doc
[`LICENSE_1_0.txt`]: LICENSE_1_0.txt
[`http://www.boost.org/LICENSE_1_0.txt`]: http://www.boost.org/LICENSE_1_0.txt
