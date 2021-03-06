# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug
endif
export config

PROJECTS := Core_Library test

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

Core_Library: 
	@echo "==== Building Core_Library ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Core_Library.make

test: Core_Library
	@echo "==== Building test ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f test.make

clean:
	@${MAKE} --no-print-directory -C . -f Core_Library.make clean
	@${MAKE} --no-print-directory -C . -f test.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo "   debug32"
	@echo "   release32"
	@echo "   debug64"
	@echo "   release64"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Core_Library"
	@echo "   test"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
