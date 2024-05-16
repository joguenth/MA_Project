//
// Generated file, do not edit! Created by nedtool 5.5 from core4inet/linklayer/ethernet/AS6802/PCFrame.msg.
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
#include "PCFrame_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("CoRE4INET::PCFType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("CoRE4INET::PCFType"));
    e->insert(CS_FRAME, "CS_FRAME");
    e->insert(IN_FRAME, "IN_FRAME");
    e->insert(CA_FRAME, "CA_FRAME");
)

Register_Class(PCFrame)

PCFrame::PCFrame(const char *name, short kind) : ::CoRE4INET::RCFrame(name,kind)
{
    this->setByteLength(64);

    this->integration_cycle = 0;
    this->membership_new = 0;
    this->sync_priority = 0;
    this->sync_domain = 0;
    this->type = 0;
    this->transparent_clock = 0;
    this->displayString = "b=15,15,rect,white,orange,5";
}

PCFrame::PCFrame(const PCFrame& other) : ::CoRE4INET::RCFrame(other)
{
    copy(other);
}

PCFrame::~PCFrame()
{
}

PCFrame& PCFrame::operator=(const PCFrame& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::RCFrame::operator=(other);
    copy(other);
    return *this;
}

void PCFrame::copy(const PCFrame& other)
{
    this->integration_cycle = other.integration_cycle;
    this->membership_new = other.membership_new;
    this->sync_priority = other.sync_priority;
    this->sync_domain = other.sync_domain;
    this->type = other.type;
    this->transparent_clock = other.transparent_clock;
    this->displayString = other.displayString;
}

void PCFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::RCFrame::parsimPack(b);
    doParsimPacking(b,this->integration_cycle);
    doParsimPacking(b,this->membership_new);
    doParsimPacking(b,this->sync_priority);
    doParsimPacking(b,this->sync_domain);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->transparent_clock);
    doParsimPacking(b,this->displayString);
}

void PCFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::RCFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->integration_cycle);
    doParsimUnpacking(b,this->membership_new);
    doParsimUnpacking(b,this->sync_priority);
    doParsimUnpacking(b,this->sync_domain);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->transparent_clock);
    doParsimUnpacking(b,this->displayString);
}

uint32_t PCFrame::getIntegration_cycle() const
{
    return this->integration_cycle;
}

void PCFrame::setIntegration_cycle(uint32_t integration_cycle)
{
    this->integration_cycle = integration_cycle;
}

uint32_t PCFrame::getMembership_new() const
{
    return this->membership_new;
}

void PCFrame::setMembership_new(uint32_t membership_new)
{
    this->membership_new = membership_new;
}

uint8_t PCFrame::getSync_priority() const
{
    return this->sync_priority;
}

void PCFrame::setSync_priority(uint8_t sync_priority)
{
    this->sync_priority = sync_priority;
}

uint8_t PCFrame::getSync_domain() const
{
    return this->sync_domain;
}

void PCFrame::setSync_domain(uint8_t sync_domain)
{
    this->sync_domain = sync_domain;
}

uint8_t PCFrame::getType() const
{
    return this->type;
}

void PCFrame::setType(uint8_t type)
{
    this->type = type;
}

uint64_t PCFrame::getTransparent_clock() const
{
    return this->transparent_clock;
}

void PCFrame::setTransparent_clock(uint64_t transparent_clock)
{
    this->transparent_clock = transparent_clock;
}

const char * PCFrame::getDisplayString() const
{
    return this->displayString.c_str();
}

void PCFrame::setDisplayString(const char * displayString)
{
    this->displayString = displayString;
}

class PCFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PCFrameDescriptor();
    virtual ~PCFrameDescriptor();

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

Register_ClassDescriptor(PCFrameDescriptor)

PCFrameDescriptor::PCFrameDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::PCFrame", "CoRE4INET::RCFrame")
{
    propertynames = nullptr;
}

PCFrameDescriptor::~PCFrameDescriptor()
{
    delete[] propertynames;
}

bool PCFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PCFrame *>(obj)!=nullptr;
}

const char **PCFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PCFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PCFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int PCFrameDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *PCFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "integration_cycle",
        "membership_new",
        "sync_priority",
        "sync_domain",
        "type",
        "transparent_clock",
        "displayString",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int PCFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "integration_cycle")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "membership_new")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sync_priority")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sync_domain")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "transparent_clock")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PCFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "uint32_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint64_t",
        "string",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **PCFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PCFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4:
            if (!strcmp(propertyname,"enum")) return "CoRE4INET::PCFType";
            return nullptr;
        default: return nullptr;
    }
}

int PCFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PCFrame *pp = (PCFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PCFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PCFrame *pp = (PCFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PCFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PCFrame *pp = (PCFrame *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getIntegration_cycle());
        case 1: return ulong2string(pp->getMembership_new());
        case 2: return ulong2string(pp->getSync_priority());
        case 3: return ulong2string(pp->getSync_domain());
        case 4: return enum2string(pp->getType(), "CoRE4INET::PCFType");
        case 5: return uint642string(pp->getTransparent_clock());
        case 6: return oppstring2string(pp->getDisplayString());
        default: return "";
    }
}

bool PCFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PCFrame *pp = (PCFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setIntegration_cycle(string2ulong(value)); return true;
        case 1: pp->setMembership_new(string2ulong(value)); return true;
        case 2: pp->setSync_priority(string2ulong(value)); return true;
        case 3: pp->setSync_domain(string2ulong(value)); return true;
        case 4: pp->setType((CoRE4INET::PCFType)string2enum(value, "CoRE4INET::PCFType")); return true;
        case 5: pp->setTransparent_clock(string2uint64(value)); return true;
        case 6: pp->setDisplayString((value)); return true;
        default: return false;
    }
}

const char *PCFrameDescriptor::getFieldStructName(int field) const
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

void *PCFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PCFrame *pp = (PCFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace CoRE4INET

