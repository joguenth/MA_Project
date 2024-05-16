//
// Generated file, do not edit! Created by nedtool 5.5 from openflow/messages/OFP_Port_Mod.msg.
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
#include "OFP_Port_Mod_m.h"

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

namespace openflow {

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

Register_Class(OFP_Port_Mod)

OFP_Port_Mod::OFP_Port_Mod(const char *name, short kind) : ::openflow::Open_Flow_Message(name,kind)
{
    this->port_no = 0;
    for (unsigned int i=0; i<6; i++)
        this->hw_addr[i] = 0;
    this->config = 0;
    this->mask = 0;
    this->advertise = 0;
}

OFP_Port_Mod::OFP_Port_Mod(const OFP_Port_Mod& other) : ::openflow::Open_Flow_Message(other)
{
    copy(other);
}

OFP_Port_Mod::~OFP_Port_Mod()
{
}

OFP_Port_Mod& OFP_Port_Mod::operator=(const OFP_Port_Mod& other)
{
    if (this==&other) return *this;
    ::openflow::Open_Flow_Message::operator=(other);
    copy(other);
    return *this;
}

void OFP_Port_Mod::copy(const OFP_Port_Mod& other)
{
    this->port_no = other.port_no;
    for (unsigned int i=0; i<6; i++)
        this->hw_addr[i] = other.hw_addr[i];
    this->config = other.config;
    this->mask = other.mask;
    this->advertise = other.advertise;
}

void OFP_Port_Mod::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::openflow::Open_Flow_Message::parsimPack(b);
    doParsimPacking(b,this->port_no);
    doParsimArrayPacking(b,this->hw_addr,6);
    doParsimPacking(b,this->config);
    doParsimPacking(b,this->mask);
    doParsimPacking(b,this->advertise);
}

void OFP_Port_Mod::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::openflow::Open_Flow_Message::parsimUnpack(b);
    doParsimUnpacking(b,this->port_no);
    doParsimArrayUnpacking(b,this->hw_addr,6);
    doParsimUnpacking(b,this->config);
    doParsimUnpacking(b,this->mask);
    doParsimUnpacking(b,this->advertise);
}

uint32_t OFP_Port_Mod::getPort_no() const
{
    return this->port_no;
}

void OFP_Port_Mod::setPort_no(uint32_t port_no)
{
    this->port_no = port_no;
}

unsigned int OFP_Port_Mod::getHw_addrArraySize() const
{
    return 6;
}

uint8_t OFP_Port_Mod::getHw_addr(unsigned int k) const
{
    if (k>=6) throw omnetpp::cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    return this->hw_addr[k];
}

void OFP_Port_Mod::setHw_addr(unsigned int k, uint8_t hw_addr)
{
    if (k>=6) throw omnetpp::cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    this->hw_addr[k] = hw_addr;
}

uint32_t OFP_Port_Mod::getConfig() const
{
    return this->config;
}

void OFP_Port_Mod::setConfig(uint32_t config)
{
    this->config = config;
}

uint32_t OFP_Port_Mod::getMask() const
{
    return this->mask;
}

void OFP_Port_Mod::setMask(uint32_t mask)
{
    this->mask = mask;
}

uint32_t OFP_Port_Mod::getAdvertise() const
{
    return this->advertise;
}

void OFP_Port_Mod::setAdvertise(uint32_t advertise)
{
    this->advertise = advertise;
}

class OFP_Port_ModDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OFP_Port_ModDescriptor();
    virtual ~OFP_Port_ModDescriptor();

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

Register_ClassDescriptor(OFP_Port_ModDescriptor)

OFP_Port_ModDescriptor::OFP_Port_ModDescriptor() : omnetpp::cClassDescriptor("openflow::OFP_Port_Mod", "openflow::Open_Flow_Message")
{
    propertynames = nullptr;
}

OFP_Port_ModDescriptor::~OFP_Port_ModDescriptor()
{
    delete[] propertynames;
}

bool OFP_Port_ModDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OFP_Port_Mod *>(obj)!=nullptr;
}

const char **OFP_Port_ModDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OFP_Port_ModDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OFP_Port_ModDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OFP_Port_ModDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OFP_Port_ModDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "port_no",
        "hw_addr",
        "config",
        "mask",
        "advertise",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OFP_Port_ModDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "port_no")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hw_addr")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "config")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "mask")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertise")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OFP_Port_ModDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "uint8_t",
        "uint32_t",
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OFP_Port_ModDescriptor::getFieldPropertyNames(int field) const
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

const char *OFP_Port_ModDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OFP_Port_ModDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OFP_Port_Mod *pp = (OFP_Port_Mod *)object; (void)pp;
    switch (field) {
        case 1: return 6;
        default: return 0;
    }
}

const char *OFP_Port_ModDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Port_Mod *pp = (OFP_Port_Mod *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OFP_Port_ModDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Port_Mod *pp = (OFP_Port_Mod *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPort_no());
        case 1: return ulong2string(pp->getHw_addr(i));
        case 2: return ulong2string(pp->getConfig());
        case 3: return ulong2string(pp->getMask());
        case 4: return ulong2string(pp->getAdvertise());
        default: return "";
    }
}

bool OFP_Port_ModDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OFP_Port_Mod *pp = (OFP_Port_Mod *)object; (void)pp;
    switch (field) {
        case 0: pp->setPort_no(string2ulong(value)); return true;
        case 1: pp->setHw_addr(i,string2ulong(value)); return true;
        case 2: pp->setConfig(string2ulong(value)); return true;
        case 3: pp->setMask(string2ulong(value)); return true;
        case 4: pp->setAdvertise(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OFP_Port_ModDescriptor::getFieldStructName(int field) const
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

void *OFP_Port_ModDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OFP_Port_Mod *pp = (OFP_Port_Mod *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace openflow

