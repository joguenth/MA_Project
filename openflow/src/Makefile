#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)OpenFlow
#
# This file was generated with the command:
#  opp_makemake --make-so -f --deep -O out -KINET_PROJ=../../inet -DINET_IMPORT -I. -I$$\(INET_PROJ\)/src -L$$\(INET_PROJ\)/src -lINET$$\(D\)
#

# Name of target to be created (-o option)
TARGET = $(LIB_PREFIX)OpenFlow$(D)$(SHARED_LIB_SUFFIX)
TARGET_DIR = .

# C++ include paths (with -I)
INCLUDE_PATH = -I. -I$(INET_PROJ)/src

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
    $O/openflow/controllerApps/AbstractControllerApp.o \
    $O/openflow/controllerApps/AbstractTCPControllerApp.o \
    $O/openflow/controllerApps/ARPResponder.o \
    $O/openflow/controllerApps/Hub.o \
    $O/openflow/controllerApps/LearningSwitch.o \
    $O/openflow/controllerApps/LLDPAgent.o \
    $O/openflow/controllerApps/LLDPBalancedMinHop.o \
    $O/openflow/controllerApps/LLDPForwarding.o \
    $O/openflow/controllerApps/LLDPMib.o \
    $O/openflow/controllerApps/LLDPMibGraph.o \
    $O/openflow/hostApps/LocalityPingAppRandom.o \
    $O/openflow/hostApps/PingAppRandom.o \
    $O/openflow/hostApps/TCPTrafficGeneratorApp.o \
    $O/openflow/hostApps/TCPTrafficSinkApp.o \
    $O/openflow/hyperflow/HF_ARPResponder.o \
    $O/openflow/hyperflow/HF_LLDPAgent.o \
    $O/openflow/hyperflow/HF_ReFire_Wrapper.o \
    $O/openflow/hyperflow/HyperFlowAgent.o \
    $O/openflow/hyperflow/HyperFlowSynchronizer.o \
    $O/openflow/kandoo/KandooAgent.o \
    $O/openflow/kandoo/KN_ARPResponder.o \
    $O/openflow/kandoo/KN_LLDPAgent.o \
    $O/openflow/kandoo/KN_LLDPBalancedMinHop.o \
    $O/openflow/kandoo/KN_LLDPForwarding.o \
    $O/openflow/openflow/controller/Host_Profile.o \
    $O/openflow/openflow/controller/OF_Controller.o \
    $O/openflow/openflow/controller/Stream.o \
    $O/openflow/openflow/controller/StreamStore.o \
    $O/openflow/openflow/controller/Switch_Info.o \
    $O/openflow/openflow/protocol/OF100MatchBuilder.o \
    $O/openflow/openflow/protocol/OF100MessageFactory.o \
    $O/openflow/openflow/protocol/OFMatchFactory.o \
    $O/openflow/openflow/protocol/OFMessageFactory.o \
    $O/openflow/openflow/switch/Buffer.o \
    $O/openflow/openflow/switch/Flow_Table.o \
    $O/openflow/openflow/switch/Flow_Table_Entry.o \
    $O/openflow/openflow/switch/OF_Switch.o \
    $O/openflow/openflow/switch/flowtable/OF100_FlowTableEntry.o \
    $O/openflow/openflow/switch/flowtable/OF_FlowTable.o \
    $O/openflow/openflow/switch/flowtable/OF_FlowTableEntry.o \
    $O/openflow/utility/ARP_Wrapper.o \
    $O/openflow/utility/ControllerInvolvmentFilter.o \
    $O/openflow/utility/LLDP_Wrapper.o \
    $O/openflow/utility/OpenFlowGraphAnalyzer.o \
    $O/openflow/utility/StaticSpanningTree.o \
    $O/openflow/messages/HF_ChangeNotification_m.o \
    $O/openflow/messages/HF_ReportIn_m.o \
    $O/openflow/messages/HF_SyncReply_m.o \
    $O/openflow/messages/HF_SyncRequest_m.o \
    $O/openflow/messages/KN_Packet_m.o \
    $O/openflow/messages/LLDP_m.o \
    $O/openflow/messages/OFP_Features_Reply_m.o \
    $O/openflow/messages/OFP_Features_Request_m.o \
    $O/openflow/messages/OFP_Flow_Mod_m.o \
    $O/openflow/messages/OFP_Hello_m.o \
    $O/openflow/messages/OFP_Initialize_Handshake_m.o \
    $O/openflow/messages/OFP_Packet_In_m.o \
    $O/openflow/messages/OFP_Packet_Out_m.o \
    $O/openflow/messages/OFP_Port_Mod_m.o \
    $O/openflow/messages/OFP_Stats_Reply_m.o \
    $O/openflow/messages/Open_Flow_Message_m.o

# Message files
MSGFILES = \
    openflow/messages/HF_ChangeNotification.msg \
    openflow/messages/HF_ReportIn.msg \
    openflow/messages/HF_SyncReply.msg \
    openflow/messages/HF_SyncRequest.msg \
    openflow/messages/KN_Packet.msg \
    openflow/messages/LLDP.msg \
    openflow/messages/OFP_Features_Reply.msg \
    openflow/messages/OFP_Features_Request.msg \
    openflow/messages/OFP_Flow_Mod.msg \
    openflow/messages/OFP_Hello.msg \
    openflow/messages/OFP_Initialize_Handshake.msg \
    openflow/messages/OFP_Packet_In.msg \
    openflow/messages/OFP_Packet_Out.msg \
    openflow/messages/OFP_Port_Mod.msg \
    openflow/messages/OFP_Stats_Reply.msg \
    openflow/messages/Open_Flow_Message.msg

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