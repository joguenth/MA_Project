//
// Generated file, do not edit! Created by nedtool 5.5 from openflow/messages/KN_Packet.msg.
//

#ifndef __OPENFLOW_KN_PACKET_M_H
#define __OPENFLOW_KN_PACKET_M_H

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
    #include "openflow/utility/KandooStructs.h"
// }}


namespace openflow {

/**
 * Class generated from <tt>openflow/messages/KN_Packet.msg:14</tt> by nedtool.
 * <pre>
 * // When packets are received by the data plane and sent to the connected controller,
 * // the OFP_PACKET_IN messages are used. If the complete packet needs to be sent to the controller, because it can not be
 * // stored in the bufer, it is encapsulated in the packet-in message.
 * packet KN_Packet
 * {
 *     KandooEntry knEntry;
 * }
 * </pre>
 */
class KN_Packet : public ::omnetpp::cPacket
{
  protected:
    KandooEntry knEntry;

  private:
    void copy(const KN_Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KN_Packet&);

  public:
    KN_Packet(const char *name=nullptr, short kind=0);
    KN_Packet(const KN_Packet& other);
    virtual ~KN_Packet();
    KN_Packet& operator=(const KN_Packet& other);
    virtual KN_Packet *dup() const override {return new KN_Packet(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual KandooEntry& getKnEntry();
    virtual const KandooEntry& getKnEntry() const {return const_cast<KN_Packet*>(this)->getKnEntry();}
    virtual void setKnEntry(const KandooEntry& knEntry);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const KN_Packet& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, KN_Packet& obj) {obj.parsimUnpack(b);}

} // namespace openflow

#endif // ifndef __OPENFLOW_KN_PACKET_M_H
