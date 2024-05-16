//
// Generated file, do not edit! Created by nedtool 5.5 from core4inet/linklayer/ethernet/avb/SRPFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "SRPFrame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace CoRE4INET {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(SRPFrame)

SRPFrame::SRPFrame(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->streamID = 0;
    this->displayString = "b=15,15,rect,black,black,5";
}

SRPFrame::SRPFrame(const SRPFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SRPFrame::~SRPFrame()
{
}

SRPFrame& SRPFrame::operator=(const SRPFrame& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SRPFrame::copy(const SRPFrame& other)
{
    this->streamID = other.streamID;
    this->displayString = other.displayString;
}

void SRPFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->streamID);
    doParsimPacking(b,this->displayString);
}

void SRPFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->streamID);
    doParsimUnpacking(b,this->displayString);
}

uint64_t SRPFrame::getStreamID() const
{
    return this->streamID;
}

void SRPFrame::setStreamID(uint64_t streamID)
{
    this->streamID = streamID;
}

const char * SRPFrame::getDisplayString() const
{
    return this->displayString.c_str();
}

void SRPFrame::setDisplayString(const char * displayString)
{
    this->displayString = displayString;
}

class SRPFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SRPFrameDescriptor();
    virtual ~SRPFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(SRPFrameDescriptor)

SRPFrameDescriptor::SRPFrameDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::SRPFrame", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SRPFrameDescriptor::~SRPFrameDescriptor()
{
    delete[] propertynames;
}

bool SRPFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SRPFrame *>(obj)!=nullptr;
}

const char **SRPFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SRPFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SRPFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SRPFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SRPFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "streamID",
        "displayString",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SRPFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "streamID")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SRPFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SRPFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SRPFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SRPFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SRPFrame *pp = (SRPFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SRPFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SRPFrame *pp = (SRPFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SRPFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SRPFrame *pp = (SRPFrame *)object; (void)pp;
    switch (field) {
        case 0: return uint642string(pp->getStreamID());
        case 1: return oppstring2string(pp->getDisplayString());
        default: return "";
    }
}

bool SRPFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SRPFrame *pp = (SRPFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setStreamID(string2uint64(value)); return true;
        case 1: pp->setDisplayString((value)); return true;
        default: return false;
    }
}

const char *SRPFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *SRPFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SRPFrame *pp = (SRPFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TalkerAdvertise)

TalkerAdvertise::TalkerAdvertise(const char *name, short kind) : ::CoRE4INET::SRPFrame(name,kind)
{
    this->setByteLength(25);

    this->vlan_identifier = 0;
    this->MaxFrameSize = 0;
    this->MaxIntervalFrames = 0;
    this->priorityAndRank = 0;
    this->accumulatedLatency = 0;
}

TalkerAdvertise::TalkerAdvertise(const TalkerAdvertise& other) : ::CoRE4INET::SRPFrame(other)
{
    copy(other);
}

TalkerAdvertise::~TalkerAdvertise()
{
}

TalkerAdvertise& TalkerAdvertise::operator=(const TalkerAdvertise& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::SRPFrame::operator=(other);
    copy(other);
    return *this;
}

void TalkerAdvertise::copy(const TalkerAdvertise& other)
{
    this->destination_address = other.destination_address;
    this->vlan_identifier = other.vlan_identifier;
    this->MaxFrameSize = other.MaxFrameSize;
    this->MaxIntervalFrames = other.MaxIntervalFrames;
    this->priorityAndRank = other.priorityAndRank;
    this->accumulatedLatency = other.accumulatedLatency;
    this->source_address = other.source_address;
}

void TalkerAdvertise::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::SRPFrame::parsimPack(b);
    doParsimPacking(b,this->destination_address);
    doParsimPacking(b,this->vlan_identifier);
    doParsimPacking(b,this->MaxFrameSize);
    doParsimPacking(b,this->MaxIntervalFrames);
    doParsimPacking(b,this->priorityAndRank);
    doParsimPacking(b,this->accumulatedLatency);
    doParsimUnpacking(b,this->source_address);

}

void TalkerAdvertise::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::SRPFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->destination_address);
    doParsimUnpacking(b,this->vlan_identifier);
    doParsimUnpacking(b,this->MaxFrameSize);
    doParsimUnpacking(b,this->MaxIntervalFrames);
    doParsimUnpacking(b,this->priorityAndRank);
    doParsimUnpacking(b,this->accumulatedLatency);
    doParsimUnpacking(b,this->source_address);
}

inet::MACAddress& TalkerAdvertise::getDestination_address()
{
    return this->destination_address;
}

void TalkerAdvertise::setDestination_address(const inet::MACAddress& destination_address)
{
    this->destination_address = destination_address;
}

uint16_t TalkerAdvertise::getVlan_identifier() const
{
    return this->vlan_identifier;
}

void TalkerAdvertise::setVlan_identifier(uint16_t vlan_identifier)
{
    this->vlan_identifier = vlan_identifier;
}

uint16_t TalkerAdvertise::getMaxFrameSize() const
{
    return this->MaxFrameSize;
}

void TalkerAdvertise::setMaxFrameSize(uint16_t MaxFrameSize)
{
    this->MaxFrameSize = MaxFrameSize;
}

uint16_t TalkerAdvertise::getMaxIntervalFrames() const
{
    return this->MaxIntervalFrames;
}

void TalkerAdvertise::setMaxIntervalFrames(uint16_t MaxIntervalFrames)
{
    this->MaxIntervalFrames = MaxIntervalFrames;
}

uint8_t TalkerAdvertise::getPriorityAndRank() const
{
    return this->priorityAndRank;
}

void TalkerAdvertise::setPriorityAndRank(uint8_t priorityAndRank)
{
    this->priorityAndRank = priorityAndRank;
}

uint32_t TalkerAdvertise::getAccumulatedLatency() const
{
    return this->accumulatedLatency;
}

void TalkerAdvertise::setAccumulatedLatency(uint32_t accumulatedLatency)
{
    this->accumulatedLatency = accumulatedLatency;
}

inet::MACAddress& TalkerAdvertise::getSource_address()
{
    return this->source_address;
}

void TalkerAdvertise::setSource_address(const inet::MACAddress& source_address)
{
    this->source_address = source_address;
}

class TalkerAdvertiseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TalkerAdvertiseDescriptor();
    virtual ~TalkerAdvertiseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(TalkerAdvertiseDescriptor)

TalkerAdvertiseDescriptor::TalkerAdvertiseDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::TalkerAdvertise", "CoRE4INET::SRPFrame")
{
    propertynames = nullptr;
}

TalkerAdvertiseDescriptor::~TalkerAdvertiseDescriptor()
{
    delete[] propertynames;
}

bool TalkerAdvertiseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TalkerAdvertise *>(obj)!=nullptr;
}

const char **TalkerAdvertiseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TalkerAdvertiseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TalkerAdvertiseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int TalkerAdvertiseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *TalkerAdvertiseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destination_address",
        "vlan_identifier",
        "MaxFrameSize",
        "MaxIntervalFrames",
        "priorityAndRank",
        "accumulatedLatency",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int TalkerAdvertiseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination_address")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlan_identifier")==0) return base+1;
    if (fieldName[0]=='M' && strcmp(fieldName, "MaxFrameSize")==0) return base+2;
    if (fieldName[0]=='M' && strcmp(fieldName, "MaxIntervalFrames")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priorityAndRank")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "accumulatedLatency")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TalkerAdvertiseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MACAddress",
        "uint16_t",
        "uint16_t",
        "uint16_t",
        "uint8_t",
        "uint32_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **TalkerAdvertiseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TalkerAdvertiseDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TalkerAdvertiseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TalkerAdvertise *pp = (TalkerAdvertise *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TalkerAdvertiseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TalkerAdvertise *pp = (TalkerAdvertise *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TalkerAdvertiseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TalkerAdvertise *pp = (TalkerAdvertise *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDestination_address(); return out.str();}
        case 1: return ulong2string(pp->getVlan_identifier());
        case 2: return ulong2string(pp->getMaxFrameSize());
        case 3: return ulong2string(pp->getMaxIntervalFrames());
        case 4: return ulong2string(pp->getPriorityAndRank());
        case 5: return ulong2string(pp->getAccumulatedLatency());
        default: return "";
    }
}

bool TalkerAdvertiseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TalkerAdvertise *pp = (TalkerAdvertise *)object; (void)pp;
    switch (field) {
        case 1: pp->setVlan_identifier(string2ulong(value)); return true;
        case 2: pp->setMaxFrameSize(string2ulong(value)); return true;
        case 3: pp->setMaxIntervalFrames(string2ulong(value)); return true;
        case 4: pp->setPriorityAndRank(string2ulong(value)); return true;
        case 5: pp->setAccumulatedLatency(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TalkerAdvertiseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(inet::MACAddress));
        default: return nullptr;
    };
}

void *TalkerAdvertiseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TalkerAdvertise *pp = (TalkerAdvertise *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDestination_address()); break;
        default: return nullptr;
    }
}

Register_Class(TalkerFailed)

TalkerFailed::TalkerFailed(const char *name, short kind) : ::CoRE4INET::TalkerAdvertise(name,kind)
{
    this->setByteLength(34);
}

TalkerFailed::TalkerFailed(const TalkerFailed& other) : ::CoRE4INET::TalkerAdvertise(other)
{
    copy(other);
}

TalkerFailed::~TalkerFailed()
{
}

TalkerFailed& TalkerFailed::operator=(const TalkerFailed& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::TalkerAdvertise::operator=(other);
    copy(other);
    return *this;
}

void TalkerFailed::copy(const TalkerFailed& other)
{
}

void TalkerFailed::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::TalkerAdvertise::parsimPack(b);
}

void TalkerFailed::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::TalkerAdvertise::parsimUnpack(b);
}

class TalkerFailedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TalkerFailedDescriptor();
    virtual ~TalkerFailedDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(TalkerFailedDescriptor)

TalkerFailedDescriptor::TalkerFailedDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::TalkerFailed", "CoRE4INET::TalkerAdvertise")
{
    propertynames = nullptr;
}

TalkerFailedDescriptor::~TalkerFailedDescriptor()
{
    delete[] propertynames;
}

bool TalkerFailedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TalkerFailed *>(obj)!=nullptr;
}

const char **TalkerFailedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TalkerFailedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TalkerFailedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TalkerFailedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TalkerFailedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TalkerFailedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TalkerFailedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TalkerFailedDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TalkerFailedDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TalkerFailedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TalkerFailed *pp = (TalkerFailed *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TalkerFailedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TalkerFailed *pp = (TalkerFailed *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TalkerFailedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TalkerFailed *pp = (TalkerFailed *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TalkerFailedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TalkerFailed *pp = (TalkerFailed *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TalkerFailedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TalkerFailedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TalkerFailed *pp = (TalkerFailed *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ListenerReady)

ListenerReady::ListenerReady(const char *name, short kind) : ::CoRE4INET::SRPFrame(name,kind)
{
    this->setByteLength(8);

    this->vlan_identifier = 0;
}

ListenerReady::ListenerReady(const ListenerReady& other) : ::CoRE4INET::SRPFrame(other)
{
    copy(other);
}

ListenerReady::~ListenerReady()
{
}

ListenerReady& ListenerReady::operator=(const ListenerReady& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::SRPFrame::operator=(other);
    copy(other);
    return *this;
}

void ListenerReady::copy(const ListenerReady& other)
{
    this->vlan_identifier = other.vlan_identifier;
}

void ListenerReady::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::SRPFrame::parsimPack(b);
    doParsimPacking(b,this->vlan_identifier);
}

void ListenerReady::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::SRPFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->vlan_identifier);
}

uint16_t ListenerReady::getVlan_identifier() const
{
    return this->vlan_identifier;
}

void ListenerReady::setVlan_identifier(uint16_t vlan_identifier)
{
    this->vlan_identifier = vlan_identifier;
}

class ListenerReadyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ListenerReadyDescriptor();
    virtual ~ListenerReadyDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ListenerReadyDescriptor)

ListenerReadyDescriptor::ListenerReadyDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::ListenerReady", "CoRE4INET::SRPFrame")
{
    propertynames = nullptr;
}

ListenerReadyDescriptor::~ListenerReadyDescriptor()
{
    delete[] propertynames;
}

bool ListenerReadyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ListenerReady *>(obj)!=nullptr;
}

const char **ListenerReadyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ListenerReadyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ListenerReadyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ListenerReadyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ListenerReadyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vlan_identifier",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int ListenerReadyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlan_identifier")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ListenerReadyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **ListenerReadyDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ListenerReadyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ListenerReadyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ListenerReady *pp = (ListenerReady *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ListenerReadyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ListenerReady *pp = (ListenerReady *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ListenerReadyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ListenerReady *pp = (ListenerReady *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getVlan_identifier());
        default: return "";
    }
}

bool ListenerReadyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ListenerReady *pp = (ListenerReady *)object; (void)pp;
    switch (field) {
        case 0: pp->setVlan_identifier(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ListenerReadyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ListenerReadyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ListenerReady *pp = (ListenerReady *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ListenerAskingFailed)

ListenerAskingFailed::ListenerAskingFailed(const char *name, short kind) : ::CoRE4INET::SRPFrame(name,kind)
{
    this->setByteLength(17);

    this->vlan_identifier = 0;
}

ListenerAskingFailed::ListenerAskingFailed(const ListenerAskingFailed& other) : ::CoRE4INET::SRPFrame(other)
{
    copy(other);
}

ListenerAskingFailed::~ListenerAskingFailed()
{
}

ListenerAskingFailed& ListenerAskingFailed::operator=(const ListenerAskingFailed& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::SRPFrame::operator=(other);
    copy(other);
    return *this;
}

void ListenerAskingFailed::copy(const ListenerAskingFailed& other)
{
    this->vlan_identifier = other.vlan_identifier;
}

void ListenerAskingFailed::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::SRPFrame::parsimPack(b);
    doParsimPacking(b,this->vlan_identifier);
}

void ListenerAskingFailed::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::SRPFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->vlan_identifier);
}

uint16_t ListenerAskingFailed::getVlan_identifier() const
{
    return this->vlan_identifier;
}

void ListenerAskingFailed::setVlan_identifier(uint16_t vlan_identifier)
{
    this->vlan_identifier = vlan_identifier;
}

class ListenerAskingFailedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ListenerAskingFailedDescriptor();
    virtual ~ListenerAskingFailedDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ListenerAskingFailedDescriptor)

ListenerAskingFailedDescriptor::ListenerAskingFailedDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::ListenerAskingFailed", "CoRE4INET::SRPFrame")
{
    propertynames = nullptr;
}

ListenerAskingFailedDescriptor::~ListenerAskingFailedDescriptor()
{
    delete[] propertynames;
}

bool ListenerAskingFailedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ListenerAskingFailed *>(obj)!=nullptr;
}

const char **ListenerAskingFailedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ListenerAskingFailedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ListenerAskingFailedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ListenerAskingFailedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ListenerAskingFailedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vlan_identifier",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int ListenerAskingFailedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlan_identifier")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ListenerAskingFailedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **ListenerAskingFailedDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ListenerAskingFailedDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ListenerAskingFailedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ListenerAskingFailed *pp = (ListenerAskingFailed *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ListenerAskingFailedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ListenerAskingFailed *pp = (ListenerAskingFailed *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ListenerAskingFailedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ListenerAskingFailed *pp = (ListenerAskingFailed *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getVlan_identifier());
        default: return "";
    }
}

bool ListenerAskingFailedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ListenerAskingFailed *pp = (ListenerAskingFailed *)object; (void)pp;
    switch (field) {
        case 0: pp->setVlan_identifier(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ListenerAskingFailedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ListenerAskingFailedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ListenerAskingFailed *pp = (ListenerAskingFailed *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ListenerReadyFailed)

ListenerReadyFailed::ListenerReadyFailed(const char *name, short kind) : ::CoRE4INET::ListenerReady(name,kind)
{
    this->setByteLength(17);
}

ListenerReadyFailed::ListenerReadyFailed(const ListenerReadyFailed& other) : ::CoRE4INET::ListenerReady(other)
{
    copy(other);
}

ListenerReadyFailed::~ListenerReadyFailed()
{
}

ListenerReadyFailed& ListenerReadyFailed::operator=(const ListenerReadyFailed& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::ListenerReady::operator=(other);
    copy(other);
    return *this;
}

void ListenerReadyFailed::copy(const ListenerReadyFailed& other)
{
}

void ListenerReadyFailed::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::ListenerReady::parsimPack(b);
}

void ListenerReadyFailed::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::ListenerReady::parsimUnpack(b);
}

class ListenerReadyFailedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ListenerReadyFailedDescriptor();
    virtual ~ListenerReadyFailedDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ListenerReadyFailedDescriptor)

ListenerReadyFailedDescriptor::ListenerReadyFailedDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::ListenerReadyFailed", "CoRE4INET::ListenerReady")
{
    propertynames = nullptr;
}

ListenerReadyFailedDescriptor::~ListenerReadyFailedDescriptor()
{
    delete[] propertynames;
}

bool ListenerReadyFailedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ListenerReadyFailed *>(obj)!=nullptr;
}

const char **ListenerReadyFailedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ListenerReadyFailedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ListenerReadyFailedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int ListenerReadyFailedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *ListenerReadyFailedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int ListenerReadyFailedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ListenerReadyFailedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **ListenerReadyFailedDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ListenerReadyFailedDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ListenerReadyFailedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ListenerReadyFailed *pp = (ListenerReadyFailed *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ListenerReadyFailedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ListenerReadyFailed *pp = (ListenerReadyFailed *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ListenerReadyFailedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ListenerReadyFailed *pp = (ListenerReadyFailed *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ListenerReadyFailedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ListenerReadyFailed *pp = (ListenerReadyFailed *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ListenerReadyFailedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *ListenerReadyFailedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ListenerReadyFailed *pp = (ListenerReadyFailed *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace CoRE4INET

