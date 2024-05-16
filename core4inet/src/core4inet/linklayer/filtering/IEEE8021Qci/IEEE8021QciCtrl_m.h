//
// Generated file, do not edit! Created by nedtool 5.5 from core4inet/linklayer/filtering/IEEE8021Qci/IEEE8021QciCtrl.msg.
//

#ifndef __CORE4INET_IEEE8021QCICTRL_M_H
#define __CORE4INET_IEEE8021QCICTRL_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace CoRE4INET {

/**
 * Class generated from <tt>core4inet/linklayer/filtering/IEEE8021Qci/IEEE8021QciCtrl.msg:23</tt> by nedtool.
 * <pre>
 * //
 * // Control message for the IEEE 802.1Qci implementation.
 * //
 * // \@author Philipp Meyer
 * //
 * packet IEEE8021QciCtrl
 * {
 *     unsigned int gateID;
 *     unsigned int meterID;
 * }
 * </pre>
 */
class IEEE8021QciCtrl : public ::omnetpp::cPacket
{
  protected:
    unsigned int gateID;
    unsigned int meterID;

  private:
    void copy(const IEEE8021QciCtrl& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IEEE8021QciCtrl&);

  public:
    IEEE8021QciCtrl(const char *name=nullptr, short kind=0);
    IEEE8021QciCtrl(const IEEE8021QciCtrl& other);
    virtual ~IEEE8021QciCtrl();
    IEEE8021QciCtrl& operator=(const IEEE8021QciCtrl& other);
    virtual IEEE8021QciCtrl *dup() const override {return new IEEE8021QciCtrl(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned int getGateID() const;
    virtual void setGateID(unsigned int gateID);
    virtual unsigned int getMeterID() const;
    virtual void setMeterID(unsigned int meterID);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IEEE8021QciCtrl& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IEEE8021QciCtrl& obj) {obj.parsimUnpack(b);}

} // namespace CoRE4INET

#endif // ifndef __CORE4INET_IEEE8021QCICTRL_M_H

