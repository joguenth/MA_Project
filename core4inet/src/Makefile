#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)CoRE4INET
#
# This file was generated with the command:
#  opp_makemake --make-so -f --deep -O out -KINET_PROJ=../../inet -DINET_IMPORT -I. -Icore4inet/api/AS6802/tte_api -I$$\(INET_PROJ\)/src -L$$\(INET_PROJ\)/src -lINET$$\(D\) -Xcore4inet/api/AS6802 -Xcore4inet/applications/api/AS6802 -Xcore4inet/synchronisation/AS6802
#

# Name of target to be created (-o option)
TARGET = $(LIB_PREFIX)CoRE4INET$(D)$(SHARED_LIB_SUFFIX)
TARGET_DIR = .

# C++ include paths (with -I)
INCLUDE_PATH = -I. -Icore4inet/api/AS6802/tte_api -I$(INET_PROJ)/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(INET_PROJ)/src  -lINET$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/core4inet/api/base/Callback.o \
    $O/core4inet/api/base/Task.o \
    $O/core4inet/applications/AS6802/CTApplicationBase.o \
    $O/core4inet/applications/base/ApplicationBase.o \
    $O/core4inet/applications/examples/rt_tictoc/TicApp.o \
    $O/core4inet/applications/examples/rt_tictoc/TocApp.o \
    $O/core4inet/applications/trafficsink/AS6802/CTTrafficSinkApp.o \
    $O/core4inet/applications/trafficsink/AS6802/MultiTrafficSinkApp.o \
    $O/core4inet/applications/trafficsink/IEEE8021Q/IEEE8021QSRPLikeTrafficSinkApp.o \
    $O/core4inet/applications/trafficsink/IEEE8021Q/IEEE8021QTrafficSinkApp.o \
    $O/core4inet/applications/trafficsink/avb/AVBTrafficSinkApp.o \
    $O/core4inet/applications/trafficsink/base/BGTrafficSinkApp.o \
    $O/core4inet/applications/trafficsink/base/TrafficSinkApp.o \
    $O/core4inet/applications/trafficsource/AS6802/CTTrafficSourceAppBase.o \
    $O/core4inet/applications/trafficsource/AS6802/RCBurstTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/AS6802/RCTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/AS6802/TTTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QBurstTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QReservedTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QSRPLikeTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QSyncTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/avb/AVBAttackTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/avb/AVBCustomIntervalTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/avb/AVBTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/base/BGBurstTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/base/BGTrafficSourceApp.o \
    $O/core4inet/applications/trafficsource/base/TrafficSourceAppBase.o \
    $O/core4inet/applications/trafficsource/pcapng/PCAPNGTrafficSourceApp.o \
    $O/core4inet/base/NotifierConsts.o \
    $O/core4inet/buffer/AS6802/CTBuffer.o \
    $O/core4inet/buffer/AS6802/RCBuffer.o \
    $O/core4inet/buffer/AS6802/RCDoubleBuffer.o \
    $O/core4inet/buffer/AS6802/RCQueueBuffer.o \
    $O/core4inet/buffer/AS6802/TTBuffer.o \
    $O/core4inet/buffer/AS6802/TTDoubleBuffer.o \
    $O/core4inet/buffer/AS6802/TTQueueBuffer.o \
    $O/core4inet/buffer/avb/AVBBuffer.o \
    $O/core4inet/buffer/avb/AVBQueueBuffer.o \
    $O/core4inet/buffer/base/BGBuffer.o \
    $O/core4inet/buffer/base/BGQueueBuffer.o \
    $O/core4inet/buffer/base/Buffer.o \
    $O/core4inet/buffer/base/DoubleBuffer.o \
    $O/core4inet/buffer/base/QueueBuffer.o \
    $O/core4inet/incoming/AS6802/CTIncoming.o \
    $O/core4inet/incoming/AS6802/PCFIncoming.o \
    $O/core4inet/incoming/AS6802/RCIncoming.o \
    $O/core4inet/incoming/AS6802/TTIncoming.o \
    $O/core4inet/incoming/IEEE8021Qbv/IEEE8021QbvIncoming.o \
    $O/core4inet/incoming/avb/AVBIncoming.o \
    $O/core4inet/incoming/base/Incoming.o \
    $O/core4inet/linklayer/beHandling/avb/relay/SRPRelay.o \
    $O/core4inet/linklayer/ethernet/AS6802/CTFrame.o \
    $O/core4inet/linklayer/ethernet/avb/SRPEtherEncap.o \
    $O/core4inet/linklayer/ethernet/avb/SRPEtherEncapAdapter.o \
    $O/core4inet/linklayer/ethernet/avb/SRPEtherLLC.o \
    $O/core4inet/linklayer/ethernet/base/BGEtherEncap.o \
    $O/core4inet/linklayer/ethernet/base/BGEtherLLC.o \
    $O/core4inet/linklayer/filtering/NoFiltering.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/IEEE8021QciInput.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/IEEE8021QciOutput.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/filter/IEEE8021QciFilter.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/filter/MACFilter.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/filter/QTagFilter.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/gate/IEEE8021QciGate.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/gate/IEEE8021QciGateControlList.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/meter/CreditBasedMeter.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/meter/FrameSizeMeter.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/meter/IEEE8021QciMeter.o \
    $O/core4inet/linklayer/inControl/InControls.o \
    $O/core4inet/linklayer/inControl/base/BaseInControl.o \
    $O/core4inet/linklayer/shaper/Shapers.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/gate/IEEE8021QbvGate.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/gate/IEEE8021QbvGateControlList.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/queueing/IEEE8021QbvQueue.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/queueing/IEEE8021QbvQueueing.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/selection/IEEE8021QbvSelection.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/selectionAlgorithm/CreditBasedShaper.o \
    $O/core4inet/linklayer/shaper/IEEE8021Qbv/selectionAlgorithm/IEEE8021QbvSelectionAlgorithm.o \
    $O/core4inet/linklayer/shaper/base/BaseShaper.o \
    $O/core4inet/networklayer/inet/IPoRE.o \
    $O/core4inet/networklayer/inet/AS6802/IPv4oRC.o \
    $O/core4inet/networklayer/inet/AS6802/IPv4oTT.o \
    $O/core4inet/networklayer/inet/AS6802/QueuedPacket.o \
    $O/core4inet/networklayer/inet/AS6802/RCDestinationInfo.o \
    $O/core4inet/networklayer/inet/AS6802/TTDestinationInfo.o \
    $O/core4inet/networklayer/inet/IEEE8021Q/IEEE8021QDestinationInfo.o \
    $O/core4inet/networklayer/inet/IEEE8021Q/IPv4oIEEE8021Q.o \
    $O/core4inet/networklayer/inet/avb/AVBDestinationInfo.o \
    $O/core4inet/networklayer/inet/avb/IPv4oAVB.o \
    $O/core4inet/networklayer/inet/base/DestinationInfo.o \
    $O/core4inet/networklayer/inet/base/IPoREFilter.o \
    $O/core4inet/networklayer/inet/base/IPv4oREBase.o \
    $O/core4inet/networklayer/inet/base/TrafficPattern.o \
    $O/core4inet/scheduler/SchedulerEvent.o \
    $O/core4inet/scheduler/oscillator/Oscillator.o \
    $O/core4inet/scheduler/oscillator/SimpleOscillator.o \
    $O/core4inet/scheduler/period/Period.o \
    $O/core4inet/scheduler/timer/Timer.o \
    $O/core4inet/services/avb/SRP/SRProtocol.o \
    $O/core4inet/services/avb/SRP/SRPTable.o \
    $O/core4inet/synchronisation/base/DummySync.o \
    $O/core4inet/synchronisation/base/NoSync.o \
    $O/core4inet/synchronisation/base/SyncBase.o \
    $O/core4inet/utilities/ConfigFunctions.o \
    $O/core4inet/utilities/HelperFunctions.o \
    $O/core4inet/utilities/ModuleAccess.o \
    $O/core4inet/utilities/NEDFunctions.o \
    $O/core4inet/utilities/classes/AbstractSimpleModule.o \
    $O/core4inet/utilities/classes/Scheduled.o \
    $O/core4inet/utilities/classes/Timed.o \
    $O/core4inet/utilities/modules/MessageNumProfiler.o \
    $O/core4inet/utilities/pcapng/PCAPNGReader.o \
    $O/core4inet/utilities/resultfilters/ResultFilters.o \
    $O/core4inet/utilities/resultrecorders/CompareResultRecorders.o \
    $O/core4inet/utilities/resultrecorders/FloatingResultRecorders.o \
    $O/core4inet/utilities/resultrecorders/IntervalResultRecorders.o \
    $O/core4inet/applications/examples/rt_tictoc/TicToc_m.o \
    $O/core4inet/base/IPoRE/IPoREDefs_m.o \
    $O/core4inet/base/avb/AVBDefs_m.o \
    $O/core4inet/buffer/AS6802/TTBufferEmpty_m.o \
    $O/core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.o \
    $O/core4inet/linklayer/ethernet/AS6802/CTFrame_m.o \
    $O/core4inet/linklayer/ethernet/AS6802/PCFrame_m.o \
    $O/core4inet/linklayer/ethernet/AS6802/RCFrame_m.o \
    $O/core4inet/linklayer/ethernet/AS6802/TTFrame_m.o \
    $O/core4inet/linklayer/ethernet/avb/AVBFrame_m.o \
    $O/core4inet/linklayer/ethernet/avb/SRPFrame_m.o \
    $O/core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.o \
    $O/core4inet/linklayer/filtering/IEEE8021Qci/IEEE8021QciCtrl_m.o \
    $O/core4inet/scheduler/SchedulerMessage_m.o \
    $O/core4inet/scheduler/SchedulerMessageEvents_m.o \
    $O/core4inet/synchronisation/base/SyncNotification_m.o

# Message files
MSGFILES = \
    core4inet/applications/examples/rt_tictoc/TicToc.msg \
    core4inet/base/IPoRE/IPoREDefs.msg \
    core4inet/base/avb/AVBDefs.msg \
    core4inet/buffer/AS6802/TTBufferEmpty.msg \
    core4inet/linklayer/contract/ExtendedIeee802Ctrl.msg \
    core4inet/linklayer/ethernet/AS6802/CTFrame.msg \
    core4inet/linklayer/ethernet/AS6802/PCFrame.msg \
    core4inet/linklayer/ethernet/AS6802/RCFrame.msg \
    core4inet/linklayer/ethernet/AS6802/TTFrame.msg \
    core4inet/linklayer/ethernet/avb/AVBFrame.msg \
    core4inet/linklayer/ethernet/avb/SRPFrame.msg \
    core4inet/linklayer/ethernet/base/EtherFrameWithQTag.msg \
    core4inet/linklayer/filtering/IEEE8021Qci/IEEE8021QciCtrl.msg \
    core4inet/scheduler/SchedulerMessage.msg \
    core4inet/scheduler/SchedulerMessageEvents.msg \
    core4inet/synchronisation/base/SyncNotification.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)
ifneq ($(TOOLCHAIN_NAME),clangc2)
LIBS += -Wl,-rpath,$(abspath $(INET_PROJ)/src)
endif

COPTS = $(CFLAGS) $(IMPORT_DEFINES) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# inserted from file 'makefrag':
# USAGE:
# Set Environment Variables:
# EXTENDED_WARNINGS=1
# for stricter warnings and
#
# WARNINGS_ERROR=1
# for -Werror

#check for existing INET-Framework
ifeq ("$(wildcard $(INET_PROJ)/src/inet/common/INETDefs.h)","")
    $(error "Cannot find INET-Framework in the provided path: $(INET_PROJ). \
    If you need to set the location of the INET-Framework set INET_PROJ variable accordingly (e.g. "make makefiles INET_PROJ=../../path/to/inet"). \
    INET_PROJ path must be an absolute path, or a path relative to CoRE4INETs src directory")
endif

include dependencies_makefrag

CFLAGS += -std=c++11

UNAME_S := $(shell uname -s)

#Currently forcing clang interface on OS X! Otherwise OMNeT++ will use gcc wrapper of clang
ifeq ($(UNAME_S),Darwin)
	CC = clang
	CXX = clang++
	SHLIB_LD = clang++ -shared -fPIC
endif

#Special Flags for OS X
ifeq ($(UNAME_S),Darwin)
    LDFLAGS += -headerpad_max_install_names 
endif

#detect 64/32bit
LBITS := $(shell getconf LONG_BIT)
CFLAGS += -DLONG_BIT=$(LBITS)

#Warnings generate errors
ifdef WARNINGS_ERROR
	CFLAGS += -Werror
endif


#Stricter warnings in clang and gcc:
ifeq ($(CC),clang)
	#clang
	ifdef EXTENDED_WARNINGS
    CFLAGS += -Wall -Wunused -Wextra -Weverything
    endif
    CFLAGS += -Wno-padded -Wno-global-constructors -Wno-exit-time-destructors
    CFLAGS += -Wno-c++98-compat-pedantic -Wno-unknown-pragmas
    CFLAGS += -Wno-error=unused-parameter -Wno-error=header-hygiene -Wno-error=documentation -Wno-error=c++98-compat-pedantic
    CFLAGS += -Wno-error=shadow -Wno-error=missing-noreturn -Wno-error=unreachable-code -Wno-error=unreachable-code-return -Wno-error=old-style-cast
    CFLAGS += -Wno-error=conversion -Wno-error=unreachable-code-break -Wno-error=documentation-unknown-command -Wno-error=reserved-id-macro -Wno-error=unknown-warning-option
else ifeq ($(CC),gcc)
	#gcc
	ifdef EXTENDED_WARNINGS
    CFLAGS += -Wall -Wunused -Wextra -Winit-self -Wswitch-enum -Wuninitialized -Wfloat-equal -Wsuggest-attribute=pure
    CFLAGS += -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=format -Wconversion -Wuseless-cast
    CFLAGS += -Wshadow
    #CFLAGS += -ansi -pedantic-errors
    endif
    CFLAGS += -Wno-unknown-pragmas -Wno-error=unused-parameter -Wno-error=conversion -Wno-error=suggest-attribute=noreturn
    CFLAGS += -Wno-error=shadow
endif


# add -isystem for referenced projects (-I will be ignored for those also provided with -Isystem
RELPRJDOTS = $(subst o,,$(subst o ,/,$(patsubst %,..o,$(subst /, ,$(PROJECTRELATIVE_PATH)))))
ifneq (,$(findstring MSYS,$(shell uname -s)))
	# on windows we need this hack for pathes like -Id:/...
	SYSINCLUDES := $(shell echo '$(subst -I$(RELPRJDOTS)/.,-isystem $(RELPRJDOTS)/.,$(INCLUDE_PATH))' |sed -e 's/-I\($(subst \| ,\|,$(addsuffix \|,$(filter %:,$(subst :,: ,$(patsubst -I%,%,$(INCLUDE_PATH))))) \/)\)/-isystem \1/g')
else
    # on unix we can use this	
	SYSINCLUDES := $(subst -I/,-isystem /,$(subst -I$(RELPRJDOTS)/.,-isystem $(RELPRJDOTS)/.,$(INCLUDE_PATH)))
endif
override SYSINCLUDES := $(subst -I/,-isystem /,$(subst -Icore4inet/api/AS6802/tte_api,-isystem core4inet/api/AS6802/tte_api,$(SYSINCLUDES)))

COPTS += $(SYSINCLUDES) -isystem $(OMNETPP_INCL_DIR)

# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET_DIR)/$(TARGET)

$(TARGET_DIR)/% :: $O/%
	@mkdir -p $(TARGET_DIR)
	$(Q)$(LN) $< $@
ifeq ($(TOOLCHAIN_NAME),clangc2)
	$(Q)-$(LN) $(<:%.dll=%.lib) $(@:%.dll=%.lib)
endif

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc -MD -MP -MF $O/$(basename $<)_m.h.d $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning $(TARGET)
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET)
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET:%.dll=%.lib)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall:
	$(Q)$(MAKE) -s clean MODE=release
	$(Q)$(MAKE) -s clean MODE=debug
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

# include all dependencies
-include $(OBJS:%=%.d) $(MSGFILES:%.msg=$O/%_m.h.d)