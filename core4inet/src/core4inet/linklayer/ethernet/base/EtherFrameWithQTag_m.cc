//
// Generated file, do not edit! Created by nedtool 5.5 from core4inet/linklayer/ethernet/base/EtherFrameWithQTag.msg.
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
#include "EtherFrameWithQTag_m.h"

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

Register_Class(EthernetIIFrameWithQTag)

EthernetIIFrameWithQTag::EthernetIIFrameWithQTag(const char *name, short kind) : ::inet::EthernetIIFrame(name,kind)
{
    this->setByteLength(22);
    this->setEtherType(0x8100);

    this->pcp = 0;
    this->de = false;
    this->VID = 0;
    this->displayString = "b=10,10,oval,blue";

    this->streamID = 0;
    this->matchVersion = 0 ;
}

EthernetIIFrameWithQTag::EthernetIIFrameWithQTag(const EthernetIIFrameWithQTag& other) : ::inet::EthernetIIFrame(other)
{
    copy(other);
}

EthernetIIFrameWithQTag::~EthernetIIFrameWithQTag()
{
}

EthernetIIFrameWithQTag& EthernetIIFrameWithQTag::operator=(const EthernetIIFrameWithQTag& other)
{
    if (this==&other) return *this;
    ::inet::EthernetIIFrame::operator=(other);
    copy(other);
    return *this;
}

void EthernetIIFrameWithQTag::copy(const EthernetIIFrameWithQTag& other)
{
    this->pcp = other.pcp;
    this->de = other.de;
    this->VID = other.VID;
    this->displayString = other.displayString;
    this->streamID = other.streamID;
    this->matchVersion = other.matchVersion;
}

void EthernetIIFrameWithQTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::EthernetIIFrame::parsimPack(b);
    doParsimPacking(b,this->pcp);
    doParsimPacking(b,this->de);
    doParsimPacking(b,this->VID);
    doParsimPacking(b,this->displayString);
    doParsimPacking(b,this->streamID);
    doParsimUnpacking(b,this->matchVersion);
}

void EthernetIIFrameWithQTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::EthernetIIFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->pcp);
    doParsimUnpacking(b,this->de);
    doParsimUnpacking(b,this->VID);
    doParsimUnpacking(b,this->displayString);
    doParsimPacking(b,this->streamID);
    doParsimUnpacking(b,this->matchVersion);
}

uint8_t EthernetIIFrameWithQTag::getPcp() const
{
    return this->pcp;
}

void EthernetIIFrameWithQTag::setPcp(uint8_t pcp)
{
    this->pcp = pcp;
}

bool EthernetIIFrameWithQTag::getDe() const
{
    return this->de;
}

void EthernetIIFrameWithQTag::setDe(bool de)
{
    this->de = de;
}

uint16_t EthernetIIFrameWithQTag::getVID() const
{
    return this->VID;
}

void EthernetIIFrameWithQTag::setVID(uint16_t VID)
{
    this->VID = VID;
}

const char * EthernetIIFrameWithQTag::getDisplayString() const
{
    return this->displayString.c_str();
}

void EthernetIIFrameWithQTag::setDisplayString(const char * displayString)
{
    this->displayString = displayString;
}


unsigned long EthernetIIFrameWithQTag::getStreamID() const
{
    return this->streamID;
}

void EthernetIIFrameWithQTag::setStreamID(unsigned long streamID)
{
    this->streamID = streamID;
}

uint16_t EthernetIIFrameWithQTag::getmatchVersion() const
{
    return this->matchVersion;
}

void EthernetIIFrameWithQTag::setmatchVersion(uint16_t matchVersion)
{
    this->matchVersion = matchVersion;
}


class EthernetIIFrameWithQTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EthernetIIFrameWithQTagDescriptor();
    virtual ~EthernetIIFrameWithQTagDescriptor();

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

Register_ClassDescriptor(EthernetIIFrameWithQTagDescriptor)

EthernetIIFrameWithQTagDescriptor::EthernetIIFrameWithQTagDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::EthernetIIFrameWithQTag", "inet::EthernetIIFrame")
{
    propertynames = nullptr;
}

EthernetIIFrameWithQTagDescriptor::~EthernetIIFrameWithQTagDescriptor()
{
    delete[] propertynames;
}

bool EthernetIIFrameWithQTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetIIFrameWithQTag *>(obj)!=nullptr;
}

const char **EthernetIIFrameWithQTagDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EthernetIIFrameWithQTagDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EthernetIIFrameWithQTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EthernetIIFrameWithQTagDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *EthernetIIFrameWithQTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "pcp",
        "de",
        "VID",
        "displayString",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int EthernetIIFrameWithQTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pcp")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "de")==0) return base+1;
    if (fieldName[0]=='V' && strcmp(fieldName, "VID")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EthernetIIFrameWithQTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "bool",
        "uint16_t",
        "string",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **EthernetIIFrameWithQTagDescriptor::getFieldPropertyNames(int field) const
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

const char *EthernetIIFrameWithQTagDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EthernetIIFrameWithQTagDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EthernetIIFrameWithQTag *pp = (EthernetIIFrameWithQTag *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *EthernetIIFrameWithQTagDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EthernetIIFrameWithQTag *pp = (EthernetIIFrameWithQTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthernetIIFrameWithQTagDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EthernetIIFrameWithQTag *pp = (EthernetIIFrameWithQTag *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPcp());
        case 1: return bool2string(pp->getDe());
        case 2: return ulong2string(pp->getVID());
        case 3: return oppstring2string(pp->getDisplayString());
        default: return "";
    }
}

bool EthernetIIFrameWithQTagDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EthernetIIFrameWithQTag *pp = (EthernetIIFrameWithQTag *)object; (void)pp;
    switch (field) {
        case 0: pp->setPcp(string2ulong(value)); return true;
        case 1: pp->setDe(string2bool(value)); return true;
        case 2: pp->setVID(string2ulong(value)); return true;
        case 3: pp->setDisplayString((value)); return true;
        default: return false;
    }
}

const char *EthernetIIFrameWithQTagDescriptor::getFieldStructName(int field) const
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

void *EthernetIIFrameWithQTagDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EthernetIIFrameWithQTag *pp = (EthernetIIFrameWithQTag *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace CoRE4INET

