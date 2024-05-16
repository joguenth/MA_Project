//
// Generated file, do not edit! Created by nedtool 5.5 from openflow/messages/HF_ReportIn.msg.
//

#ifndef __OPENFLOW_HF_REPORTIN_M_H
#define __OPENFLOW_HF_REPORTIN_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
    #include "inet/linklayer/ethernet/EtherFrame_m.h"
    #include "openflow/openflow/controller/Switch_Info.h"    
    namespace openflow{
    typedef std::list<Switch_Info *> SwitchInfoList;
    } /*end namespace openflow*/
// }}


namespace openflow {

/**
 * Class generated from <tt>openflow/messages/HF_ReportIn.msg:18</tt> by nedtool.
 * <pre>
 * // When packets are received by the data plane and sent to the connected controller,
 * // the OFP_PACKET_IN messages are used. If the complete packet needs to be sent to the controller, because it can not be
 * // stored in the bufer, it is encapsulated in the packet-in message.
 * packet HF_ReportIn
 * {
 *     string controllerId;
 *     SwitchInfoList switchInfoList;
 * }
 * </pre>
 */
class HF_ReportIn : public ::omnetpp::cPacket
{
  protected:
    ::omnetpp::opp_string controllerId;
    SwitchInfoList switchInfoList;

  private:
    void copy(const HF_ReportIn& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HF_ReportIn&);

  public:
    HF_ReportIn(const char *name=nullptr, short kind=0);
    HF_ReportIn(const HF_ReportIn& other);
    virtual ~HF_ReportIn();
    HF_ReportIn& operator=(const HF_ReportIn& other);
    virtual HF_ReportIn *dup() const override {return new HF_ReportIn(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getControllerId() const;
    virtual void setControllerId(const char * controllerId);
    virtual SwitchInfoList& getSwitchInfoList();
    virtual const SwitchInfoList& getSwitchInfoList() const {return const_cast<HF_ReportIn*>(this)->getSwitchInfoList();}
    virtual void setSwitchInfoList(const SwitchInfoList& switchInfoList);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HF_ReportIn& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HF_ReportIn& obj) {obj.parsimUnpack(b);}

} // namespace openflow

#endif // ifndef __OPENFLOW_HF_REPORTIN_M_H
