//
// Generated file, do not edit! Created by nedtool 5.5 from openflow/messages/OFP_Packet_Out.msg.
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
#include "OFP_Packet_Out_m.h"

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

Register_Class(OFP_Packet_Out)

OFP_Packet_Out::OFP_Packet_Out(const char *name, short kind) : ::openflow::Open_Flow_Message(name,kind)
{
    this->buffer_id = 0;
    this->in_port = 0;
    actions_arraysize = 0;
    this->actions = 0;
    for (unsigned int i=0; i<0; i++)
        this->data[i] = 0;
}

OFP_Packet_Out::OFP_Packet_Out(const OFP_Packet_Out& other) : ::openflow::Open_Flow_Message(other)
{
    actions_arraysize = 0;
    this->actions = 0;
    copy(other);
}

OFP_Packet_Out::~OFP_Packet_Out()
{
    delete [] this->actions;
}

OFP_Packet_Out& OFP_Packet_Out::operator=(const OFP_Packet_Out& other)
{
    if (this==&other) return *this;
    ::openflow::Open_Flow_Message::operator=(other);
    copy(other);
    return *this;
}

void OFP_Packet_Out::copy(const OFP_Packet_Out& other)
{
    this->buffer_id = other.buffer_id;
    this->in_port = other.in_port;
    delete [] this->actions;
    this->actions = (other.actions_arraysize==0) ? nullptr : new ofp_action_output[other.actions_arraysize];
    actions_arraysize = other.actions_arraysize;
    for (unsigned int i=0; i<actions_arraysize; i++)
        this->actions[i] = other.actions[i];
    for (unsigned int i=0; i<0; i++)
        this->data[i] = other.data[i];
}

void OFP_Packet_Out::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::openflow::Open_Flow_Message::parsimPack(b);
    doParsimPacking(b,this->buffer_id);
    doParsimPacking(b,this->in_port);
    b->pack(actions_arraysize);
    doParsimArrayPacking(b,this->actions,actions_arraysize);
    doParsimArrayPacking(b,this->data,0);
}

void OFP_Packet_Out::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::openflow::Open_Flow_Message::parsimUnpack(b);
    doParsimUnpacking(b,this->buffer_id);
    doParsimUnpacking(b,this->in_port);
    delete [] this->actions;
    b->unpack(actions_arraysize);
    if (actions_arraysize==0) {
        this->actions = 0;
    } else {
        this->actions = new ofp_action_output[actions_arraysize];
        doParsimArrayUnpacking(b,this->actions,actions_arraysize);
    }
    doParsimArrayUnpacking(b,this->data,0);
}

uint32_t OFP_Packet_Out::getBuffer_id() const
{
    return this->buffer_id;
}

void OFP_Packet_Out::setBuffer_id(uint32_t buffer_id)
{
    this->buffer_id = buffer_id;
}

uint32_t OFP_Packet_Out::getIn_port() const
{
    return this->in_port;
}

void OFP_Packet_Out::setIn_port(uint32_t in_port)
{
    this->in_port = in_port;
}

void OFP_Packet_Out::setActionsArraySize(unsigned int size)
{
    ofp_action_output *actions2 = (size==0) ? nullptr : new ofp_action_output[size];
    unsigned int sz = actions_arraysize < size ? actions_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        actions2[i] = this->actions[i];
    actions_arraysize = size;
    delete [] this->actions;
    this->actions = actions2;
}

unsigned int OFP_Packet_Out::getActionsArraySize() const
{
    return actions_arraysize;
}

ofp_action_output& OFP_Packet_Out::getActions(unsigned int k)
{
    if (k>=actions_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", actions_arraysize, k);
    return this->actions[k];
}

void OFP_Packet_Out::setActions(unsigned int k, const ofp_action_output& actions)
{
    if (k>=actions_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", actions_arraysize, k);
    this->actions[k] = actions;
}

unsigned int OFP_Packet_Out::getDataArraySize() const
{
    return 0;
}

uint8_t OFP_Packet_Out::getData(unsigned int k) const
{
    if (k>=0) throw omnetpp::cRuntimeError("Array of size 0 indexed by %lu", (unsigned long)k);
    return this->data[k];
}

void OFP_Packet_Out::setData(unsigned int k, uint8_t data)
{
    if (k>=0) throw omnetpp::cRuntimeError("Array of size 0 indexed by %lu", (unsigned long)k);
    this->data[k] = data;
}

class OFP_Packet_OutDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OFP_Packet_OutDescriptor();
    virtual ~OFP_Packet_OutDescriptor();

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

Register_ClassDescriptor(OFP_Packet_OutDescriptor)

OFP_Packet_OutDescriptor::OFP_Packet_OutDescriptor() : omnetpp::cClassDescriptor("openflow::OFP_Packet_Out", "openflow::Open_Flow_Message")
{
    propertynames = nullptr;
}

OFP_Packet_OutDescriptor::~OFP_Packet_OutDescriptor()
{
    delete[] propertynames;
}

bool OFP_Packet_OutDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OFP_Packet_Out *>(obj)!=nullptr;
}

const char **OFP_Packet_OutDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OFP_Packet_OutDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OFP_Packet_OutDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int OFP_Packet_OutDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *OFP_Packet_OutDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "buffer_id",
        "in_port",
        "actions",
        "data",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int OFP_Packet_OutDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "buffer_id")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "in_port")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "actions")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OFP_Packet_OutDescriptor::getFieldTypeString(int field) const
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
        "ofp_action_output",
        "uint8_t",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **OFP_Packet_OutDescriptor::getFieldPropertyNames(int field) const
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

const char *OFP_Packet_OutDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OFP_Packet_OutDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OFP_Packet_Out *pp = (OFP_Packet_Out *)object; (void)pp;
    switch (field) {
        case 2: return pp->getActionsArraySize();
        case 3: return 0;
        default: return 0;
    }
}

const char *OFP_Packet_OutDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Packet_Out *pp = (OFP_Packet_Out *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OFP_Packet_OutDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Packet_Out *pp = (OFP_Packet_Out *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getBuffer_id());
        case 1: return ulong2string(pp->getIn_port());
        case 2: {std::stringstream out; out << pp->getActions(i); return out.str();}
        case 3: return ulong2string(pp->getData(i));
        default: return "";
    }
}

bool OFP_Packet_OutDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OFP_Packet_Out *pp = (OFP_Packet_Out *)object; (void)pp;
    switch (field) {
        case 0: pp->setBuffer_id(string2ulong(value)); return true;
        case 1: pp->setIn_port(string2ulong(value)); return true;
        case 3: pp->setData(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *OFP_Packet_OutDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(ofp_action_output));
        default: return nullptr;
    };
}

void *OFP_Packet_OutDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OFP_Packet_Out *pp = (OFP_Packet_Out *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getActions(i)); break;
        default: return nullptr;
    }
}

} // namespace openflow

