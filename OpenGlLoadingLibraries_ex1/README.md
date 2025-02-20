#### OpenGlLoadingLibraries_ex1

OpenGL Wiki Book - https://en.wikibooks.org/wiki/OpenGL_Programming
OpenGL - https://www.khronos.org
OpenGl - https://www.opengl.org/

freeglut - https://freeglut.sourceforge.net/docs/api.php
glut examples by sprintr - https://github.com/sprintr/opengl-examples


## Freeglut https://freeglut.sourceforge.net/ 
Github - https://github.com/freeglut/freeglut

Freeglut is a free-software/open-source alternative to the `OpenGL Utility Toolkit(GLUT)` library.
GLUT was originally written by `Mark Kilgard` to support the sample programs in the 2nd edition OpenGl `RedBook`. Now, GLUT is unsupported for 20 years.
Since then, it has been used in a wide variety of partical apps because, it is:
	simple,
	widely available, &
	highly portable.
GLUT
	https://www.opengl.org/resources/libraries/glut/
	https://www.opengl.org/resources/libraries/glut/glut_downloads.php

GLUT (& hence freeglut) takes cares of all the system-specific chores required for:
	creating windows,
	initializing OpenGL contexts, &
	handling input events
to allow for trully portable OpenGL programs.

# Setup process
Step 1. Download latest release (`freeglut-<version>.tar.gz`) from - https://github.com/freeglut/freeglut/releases
Step 2. Extract tar.gz, 7zip can extract it but we have to extract it twice. For symbolic link issue
			Error: `Cannot create symbolic link : Access is denied`
		Run 7zip with administrator priviledge from windows menu.
Step 3. Extracted folder will have structure like following:
			altbuild\
			android\
			include\
			progs\
			src\
			CMakeLists.txt
			...
		Run CMake gui or use cmake command line to create Visual Studio solution from the `CMakeList.txt` present in the 
		extracted folder.
Step 4. Compile the solution and it will create the libraries and dlls.


## OpenGL Loading Libraries
https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library
These are:
	Glad 			https://github.com/Dav1dde/glad
	glbinding(C++)	https://github.com/hpicgs/glbinding
	GLEW			http://glew.sourceforge.net/
	GL3W			https://github.com/skaslev/gl3w
	Galogen			https://galogen.gpfault.net/
	Glatter			https://github.com/imakris/glatter
	glsdk			http://glsdk.sourceforge.net/      	(Unofficial OpenGL SDK)
	libepoxy		https://github.com/anholt/libepoxy


## The OpenGL Extension Wrangler library (GLEW)
An `OpenGL loading library` that loads pointers to OpenGL functions at runtine, core as well as extensions.
This is required to access functions from OpenGL versions above 1.1 on most platforms. Extension loading libraries also absarcts away the difference
between the loading mechanisms on different platforms.

To show how to use GLFW library in C/C++.
CMakeList file on how to create a simple project with all linking.

Guide - https://glew.sourceforge.net/
Usage - https://glew.sourceforge.net/basic.html

git clone https://github.com/nigels-com/glew.git glew



OpenGL SDK - http://www.opengl.org/sdk/
OpenGL Extension Registry - http://www.opengl.org/registry/
OpenGL Wiki: Extensions - https://www.opengl.org/wiki/OpenGL_Extension
NVIDIA OpenGL Extension Specifications - http://developer.nvidia.com/nvidia-opengl-specs
Apple OpenGL Extensions Guide - http://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/OpenGLExtensionsGuide/Reference/reference.html


# Downloaded zip will extract to something like below:
	- bin/Release/
		/Win32/
			/glew32.dll
			/glewinfo.exe
			/visualinfo.exe
		/x64/
			/glew32.dll
			/glewinfo.exe
			/visualinfo.exe
	- doc/
	- include/GL/
		/eglew.h
		/glew.h
		...
	- lib/Release/
		/Wind32/
			/glew32.lib
			/glew32s.lib
		/x64/
			/glew32.lib
			/glew32s.lib


## Description
# The OpenGL Extension Wrangler library(GLEW)
GLEW is a cross-platform(Windows, Linus, Mac OS X, FreeBSD, Iris, and Solaris) open-source C/C++ extension loading library.
It provides efficient run-time mechanisms for determining which OpenGL extensions are supported
on the target platform. OpenGL core and extension functionality is exposed in a single header file.

## Utilities
GLEW provide 2 command-line Utilities:
	- for creating list of available Extensions and visuals
	- another for verifying extension entry points

**visualinfo: extension and visuals** - `visualinfo` is an extended version of `glxinfo`. The Windows version creates a file called a file called
`visualinfo.txt`, which contains a list of available OpenGL, WGL, and GLU extensions as well as a table of visuals aka. pixel formats. Pbuffer and
MRT capable visuals are also included. For additional usage info, type `visualinfo -h`.

**glewinfo: extension verification utility** - `glewinfo` allows to verify the entry points for the extensions supprted by the platform. The Windows 
version reports the results to a text file called `glewinfo.txt`. The Unix version prints the results to `stdout`.
Windows usage: `glewinfo [-pf <id>]
	where <id> is the pixel format id for which the capabilities are displayed.
	
Unix usage: `glewinfo [-display <dpy>] [-visual <id>]
	where <dpy> is the X11 display and <id> is the visual id for which the capabilities are displayed.

**See file** `glewinfo.txt` and `visualinfo.txt`



## GLAD
Github - https://github.com/Dav1dde/glad
Download - https://gen.glad.sh/
Wiki - https://github.com/Dav1dde/glad/wiki/C#quick-start

# Steps to download:

Step 1. Visit https://github.com/Dav1dde/glad
Step 2. Make below selections.
	Generator: C/C++
	APIs
		egl 		None
		gl 			<Select Latest Version>			Compatibility
		gles1 		None							Common
		gles2 		None
		glsc2 		None
		glx 		None
		vulkan 		None
		vulkansc 	None
		wgl 		None
		
NOTE: While selecting "API->gl" Version choose "Compatibility" & in "Extensions" click "ADD ALL" button.

In "Options", tick "loader    Include internal loaders for APIs".

Then click "GENERATE" button.

It will download "glad.zip" which will contain two folders:
	include\
		glad\gl.h
		KHR\khrplatform.h
	src\gl.c