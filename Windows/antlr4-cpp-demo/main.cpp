/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"


#include <Windows.h>

#pragma execution_character_set("utf-8")

using namespace antlrcpptest;
using namespace antlr4;

#include "mod.h"
#include "MyVisitor.h"

ModDef MyMod;

int main(int argc, const char * argv[]) {

	
	MyMod.addFile("src\\block_adx\\block.i");
	MyMod.addFile("src\\block_adx\\store.i");
	

	//MyMod.addFile("src\\node_adx\\node.i");

	MyMod.parse();

	MyMod.visit();

	MyMod.dump();

	 //std::wcout << "Parse Tree: " << s << std::endl; //Unicode output in the console is very limited.

  return 0;
}
