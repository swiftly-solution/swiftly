CC_COMMAND = CONFIG_CC_COMMAND
CXX_COMMAND = CONFIG_CXX_COMMAND
PROJECT_NAME = PLUGIN_NAME

CURRENT_PATH=$(realpath .)
BEHIND_PATH=$(realpath ..)
SRC_DIR := src
BUILD_DIR := output
TEMP_DIR := temp
INCLUDES_FOLDER := $(CURRENT_PATH)/includes

CC_FLAGS = -I"$(INCLUDES_FOLDER)" -I"$(BEHIND_PATH)/includes"
CXX_FLAGS := -I"$(INCLUDES_FOLDER)" -I"$(BEHIND_PATH)/includes" -lpthread -L"$(BEHIND_PATH)/lib" -std=c++17

ifneq ($(OS),Windows_NT)
	CXX_FLAGS := $(CXX_FLAGS) -fPIC
endif

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRC_FILES := $(call rwildcard,$(SRC_DIR),*.cpp)
SRC_FILES += $(call rwildcard,$(BEHIND_PATH)/includes/swiftly,*.cpp)
TEMP_OBJS_FILES = $(subst :,_,$(subst /,_,$(patsubst %.cpp, %.o, $(SRC_FILES))))
OBJS_FILES = $(patsubst %o,$(TEMP_DIR)/%o,$(TEMP_OBJS_FILES))

define COMPILE_FILE
	$(CXX_COMMAND) $(CXX_FLAGS) -o $(TEMP_DIR)/$(subst :,_,$(subst /,_,$(subst .cpp,.o,$(1)))) -c $(1)
	
endef

build:
ifeq ($(OS),Windows_NT)
	@rd /s /q $(BUILD_DIR) 2>NUL || (echo)
	@rd /s /q $(TEMP_DIR) 2>NUL || (echo)
else
	@rm -rf $(BUILD_DIR)
	@rm -rf $(TEMP_DIR)
endif
	mkdir $(TEMP_DIR)
	$(foreach src,$(SRC_FILES),$(call COMPILE_FILE,$(src)))
	
ifeq ($(OS),Windows_NT)
	xcopy .\plugin_files .\$(BUILD_DIR) /E /C /I /F /R /Y
else
	mkdir $(BUILD_DIR)
	@cp -r ./plugin_files/* ./$(BUILD_DIR)
endif

	mkdir "$(BUILD_DIR)/plugins"
	mkdir "$(BUILD_DIR)/plugins/$(PROJECT_NAME)"

ifeq ($(OS),Windows_NT)
	$(CXX_COMMAND) -shared $(CXX_FLAGS) -o $(BUILD_DIR)/plugins/$(PROJECT_NAME)/$(PROJECT_NAME).dll $(OBJS_FILES)
else
	$(CXX_COMMAND) -shared $(CXX_FLAGS) -o $(BUILD_DIR)/plugins/$(PROJECT_NAME)/$(PROJECT_NAME).so $(OBJS_FILES)
endif

ifeq ($(OS),Windows_NT)
	@rd /s /q $(TEMP_DIR) 2>NUL || (echo)
else
	@rm -rf $(TEMP_DIR)
endif