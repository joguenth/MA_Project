#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)SDN4CoRE
#
# This file was generated with the command:
#  opp_makemake --make-so -f --deep -KCORE4INET_PROJ=../../CoRE4INET -KINET_PROJ=../../inet -KOPENFLOW_PROJ=../../OpenFlow -DINET_IMPORT -I/usr/include/python2.7 -I. -I$$\(CORE4INET_PROJ\)/src -I$$\(CORE4INET_PROJ\)/src/core4inet/api/AS6802/tte_api -I$$\(INET_PROJ\)/src -I$$\(OPENFLOW_PROJ\)/src -L$$\(CORE4INET_PROJ\)/src -L$$\(INET_PROJ\)/src -L$$\(OPENFLOW_PROJ\)/src -lpython2.7 -lstdc++ -lCoRE4INET$$\(D\) -lINET$$\(D\) -lOpenFlow$$\(D\)
#

# Name of target to be created (-o option)
TARGET = $(LIB_PREFIX)SDN4CoRE$(D)$(SHARED_LIB_SUFFIX)
TARGET_DIR = .

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I/usr/include/python2.7 \
    -I. \
    -I$(CORE4INET_PROJ)/src \
    -I$(CORE4INET_PROJ)/src/core4inet/api/AS6802/tte_api \
    -I$(INET_PROJ)/src \
    -I$(OPENFLOW_PROJ)/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(CORE4INET_PROJ)/src $(LDFLAG_LIBPATH)$(INET_PROJ)/src $(LDFLAG_LIBPATH)$(OPENFLOW_PROJ)/src  -lpython2.7 -lstdc++ -lCoRE4INET$(D) -lINET$(D) -lOpenFlow$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/sdn4core/controllerApps/avb/AVBLearningControllerApp.o \
    $O/sdn4core/controllerApps/avb/AVBSecurityControllerApp.o \
    $O/sdn4core/controllerApps/commonApps/Assignment.o \
    $O/sdn4core/controllerApps/commonApps/ConfigurationEngine.o \
    $O/sdn4core/controllerApps/commonApps/Demand.o \
    $O/sdn4core/controllerApps/commonApps/RequestHandlerControllerApp.o \
    $O/sdn4core/controllerApps/mtd/MTDControllerApp.o \
    $O/sdn4core/controllerApps/opt/opce2/OPCE2.o \
    $O/sdn4core/controllerApps/shortestpath/ShortestPathControllerApp.o \
    $O/sdn4core/controllerApps/tsn/TSNLearningControllerApp.o \
    $O/sdn4core/controllerApps/utility/MACTableManagement.o \
    $O/sdn4core/controllerApps/utility/PortModule.o \
    $O/sdn4core/controllerApps/utility/SRPTableManagement.o \
    $O/sdn4core/netconf/applications/base/NetConfApplicationBase.o \
    $O/sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserCollection.o \
    $O/sdn4core/netconf/applications/configparser/multipart/NetConfAppConfigParserMultipart.o \
    $O/sdn4core/netconf/applications/configparser/openflow/NetConfAppConfigParserOpenFlow.o \
    $O/sdn4core/netconf/applications/configparser/srptable/NetConfAppConfigParserSRPTable.o \
    $O/sdn4core/netconf/applications/transactionModel/TimeSynchronousTransactionApp.o \
    $O/sdn4core/netconf/applications/transactionModel/TransactionApp.o \
    $O/sdn4core/netconf/applications/transactionModel/transactionModelTest/TransactionModelTest.o \
    $O/sdn4core/netconf/client/base/NetConfClientBase.o \
    $O/sdn4core/netconf/client/tcp/NetConfClientTCP.o \
    $O/sdn4core/netconf/datastores/config/base/NetConfDataConfiguratorBase.o \
    $O/sdn4core/netconf/datastores/config/dummy/NetConfDataConfiguratorDummy.o \
    $O/sdn4core/netconf/datastores/config/ieee8021qbv/NetConfDataConfiguratorIEEE8021Qbv.o \
    $O/sdn4core/netconf/datastores/config/multipart/NetConfDataConfiguratorMultipart.o \
    $O/sdn4core/netconf/datastores/config/openflow/NetConfDataConfiguratorFlowTable.o \
    $O/sdn4core/netconf/datastores/config/srp/NetConfDataConfiguratorSRP.o \
    $O/sdn4core/netconf/datastores/manager/base/NetConfDataStoreManagerBase.o \
    $O/sdn4core/netconf/datastores/store/base/NetConfDataStoreBase.o \
    $O/sdn4core/netconf/datastores/store/candidate/NetConfCandidateDataStore.o \
    $O/sdn4core/netconf/datastores/store/running/NetConfRunningDataStore.o \
    $O/sdn4core/netconf/datastructures/base/NetConfConfig.o \
    $O/sdn4core/netconf/datastructures/base/NetConfFilter.o \
    $O/sdn4core/netconf/datastructures/ieee8021qbv/NetConfConfigIEEE8021Qbv.o \
    $O/sdn4core/netconf/datastructures/multipart/NetConfConfigMultipart.o \
    $O/sdn4core/netconf/datastructures/openflow/OF_NetConfConfigFlowMod.o \
    $O/sdn4core/netconf/datastructures/srp/NetConfConfigSRP.o \
    $O/sdn4core/netconf/datastructures/transactionModel/NetConfConfigCommitTimestamp.o \
    $O/sdn4core/netconf/server/base/NetConfServerBase.o \
    $O/sdn4core/netconf/server/tcp/NetConfServerTCP.o \
    $O/sdn4core/switch/avb/engine/AVB_OF_RelayUnit.o \
    $O/sdn4core/switch/avb/engine/AVB_OF_SwitchAgent.o \
    $O/sdn4core/switch/avb/incoming/avb/OF_AVBIncoming.o \
    $O/sdn4core/switch/avb/port/AVBEthernetInterfaceConnection.o \
    $O/sdn4core/switch/base/engine/OF_RelayUnit.o \
    $O/sdn4core/switch/base/engine/OF_SwitchAgent.o \
    $O/sdn4core/switch/ieee8021qbv/edgeAgent/Edge_OF_SwitchAgent.o \
    $O/sdn4core/switch/ieee8021qbv/edgeRelay/Edge_OF_RelayUnit.o \
    $O/sdn4core/switch/tsn/engine/TSN_OF_RelayUnit.o \
    $O/sdn4core/utility/dynamicmodules/DynamicModuleHandling.o \
    $O/sdn4core/utility/dynamicparameters/DynamicChannelParameterChanger.o \
    $O/sdn4core/utility/dynamicparameters/DynamicParameterChanger.o \
    $O/sdn4core/utility/processing/ProcessingTimeSimulation.o \
    $O/sdn4core/utility/visual/ColorChangingNode.o \
    $O/sdn4core/utility/visual/NodeDisplayEditor.o \
    $O/sdn4core/utility/xml/XMLUtility.o \
    $O/sdn4core/netconf/messages/NetConfCapability_m.o \
    $O/sdn4core/netconf/messages/NetConfCtrlInfo_m.o \
    $O/sdn4core/netconf/messages/NetConfMessage_m.o \
    $O/sdn4core/netconf/messages/NetConfOperation_m.o

# Message files
MSGFILES = \
    sdn4core/netconf/messages/NetConfCapability.msg \
    sdn4core/netconf/messages/NetConfCtrlInfo.msg \
    sdn4core/netconf/messages/NetConfMessage.msg \
    sdn4core/netconf/messages/NetConfOperation.msg

# SM files
SMFILES =

# Other makefile variables (-K)
CORE4INET_PROJ=../../CoRE4INET
INET_PROJ=../../inet
OPENFLOW_PROJ=../../OpenFlow

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
LIBS += -Wl,-rpath,$(abspath $(CORE4INET_PROJ)/src) -Wl,-rpath,$(abspath $(INET_PROJ)/src) -Wl,-rpath,$(abspath $(OPENFLOW_PROJ)/src)
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