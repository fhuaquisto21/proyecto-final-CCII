Testing
----
C++ Standards:

![](https://img.shields.io/github/stars/pandao/editor.md.svg)

Compilers:
Visual Studio: 2017, 2019, 2022


From SFML is multi-media – A Quick Start Guide
===

![](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bf/SFML2.svg/800px-SFML2.svg.png)

SFML provides a simple interface to the various components of your PC, to ease the development of games and multimedia applications. It is composed of five modules: system, window, graphics, audio and network.

Discover their features more in detail in the tutorials and the API documentation.


Getting started
===


SFML and Visual Studio
---

Introduction
---

This tutorial is the first one you should read if you're using SFML with the Visual Studio IDE (Visual C++ compiler). It will explain how to configure your SFML projects.

Creating and configuring a SFML project
---

The first thing to do is choose what kind of project to create. It is recommended to select "Empty Project". The dialog window offers a few other options to customize the project: select "Console application" or "Windows application" only if you know how to use pre-compiled headers.
For the purpose of this tutorial, you should create a main.cpp file and add it to the project, so that we have access to the C++ settings (otherwise Visual Studio doesn't know which language you're going to use for this project). We'll explain what to put inside later.

Now we need to tell the compiler where to find the SFML headers (.hpp files), and the linker where to find the SFML libraries (.lib files).

In the project's properties, add:

+ The path to the SFML headers (<sfml-install-path>/include) to C/C++ » General » Additional Include Directories
+ The path to the SFML libraries (<sfml-install-path>/lib) to Linker » General » Additional Library Directories



