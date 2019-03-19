##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=consoleTest
ConfigurationName      :=Debug
WorkspacePath          :=/home/rgk/Projects/interconetica/external/cpp_redis
ProjectPath            :=/home/rgk/Projects/interconetica/external/cpp_redis/consola/consoleTest
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Roni Gonzalez Kalil
Date                   :=19/03/19
CodeLitePath           :=/home/rgk/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="consoleTest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -pthread
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../../includes $(IncludeSwitch)../../tacopie/includes 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)cpp_redis $(LibrarySwitch)tacopie 
ArLibs                 :=  "libcpp_redis.a" "libtacopie.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/consoleTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/pch.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/consoleTest.cpp$(ObjectSuffix): consoleTest.cpp $(IntermediateDirectory)/consoleTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rgk/Projects/interconetica/external/cpp_redis/consola/consoleTest/consoleTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/consoleTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/consoleTest.cpp$(DependSuffix): consoleTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/consoleTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/consoleTest.cpp$(DependSuffix) -MM consoleTest.cpp

$(IntermediateDirectory)/consoleTest.cpp$(PreprocessSuffix): consoleTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/consoleTest.cpp$(PreprocessSuffix) consoleTest.cpp

$(IntermediateDirectory)/pch.cpp$(ObjectSuffix): pch.cpp $(IntermediateDirectory)/pch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rgk/Projects/interconetica/external/cpp_redis/consola/consoleTest/pch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pch.cpp$(DependSuffix): pch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pch.cpp$(DependSuffix) -MM pch.cpp

$(IntermediateDirectory)/pch.cpp$(PreprocessSuffix): pch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pch.cpp$(PreprocessSuffix) pch.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


