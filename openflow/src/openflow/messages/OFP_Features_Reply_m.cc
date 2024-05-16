//
// Generated file, do not edit! Created by nedtool 5.5 from openflow/messages/OFP_Features_Reply.msg.
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
#include "OFP_Features_Reply_m.h"

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

Register_Class(OFP_Features_Reply)

OFP_Features_Reply::OFP_Features_Reply(const char *name, short kind) : ::openflow::Open_Flow_Message(name,kind)
{
    this->n_buffers = 0;
    this->n_tables = 0;
    this->capabilities = 0;
    this->reserved = 0;
    ports_arraysize = 0;
    this->ports = 0;
}

OFP_Features_Reply::OFP_Features_Reply(const OFP_Features_Reply& other) : ::openflow::Open_Flow_Message(other)
{
    ports_arraysize = 0;
    this->ports = 0;
    copy(other);
}

OFP_Features_Reply::~OFP_Features_Reply()
{
    delete [] this->ports;
}

OFP_Features_Reply& OFP_Features_Reply::operator=(const OFP_Features_Reply& other)
{
    if (this==&other) return *this;
    ::openflow::Open_Flow_Message::operator=(other);
    copy(other);
    return *this;
}

void OFP_Features_Reply::copy(const OFP_Features_Reply& other)
{
    this->datapath_id = other.datapath_id;
    this->n_buffers = other.n_buffers;
    this->n_tables = other.n_tables;
    this->capabilities = other.capabilities;
    this->reserved = other.reserved;
    delete [] this->ports;
    this->ports = (other.ports_arraysize==0) ? nullptr : new uint32_t[other.ports_arraysize];
    ports_arraysize = other.ports_arraysize;
    for (unsigned int i=0; i<ports_arraysize; i++)
        this->ports[i] = other.ports[i];
}

void OFP_Features_Reply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::openflow::Open_Flow_Message::parsimPack(b);
    doParsimPacking(b,this->datapath_id);
    doParsimPacking(b,this->n_buffers);
    doParsimPacking(b,this->n_tables);
    doParsimPacking(b,this->capabilities);
    doParsimPacking(b,this->reserved);
    b->pack(ports_arraysize);
    doParsimArrayPacking(b,this->ports,ports_arraysize);
}

void OFP_Features_Reply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::openflow::Open_Flow_Message::parsimUnpack(b);
    doParsimUnpacking(b,this->datapath_id);
    doParsimUnpacking(b,this->n_buffers);
    doParsimUnpacking(b,this->n_tables);
    doParsimUnpacking(b,this->capabilities);
    doParsimUnpacking(b,this->reserved);
    delete [] this->ports;
    b->unpack(ports_arraysize);
    if (ports_arraysize==0) {
        this->ports = 0;
    } else {
        this->ports = new uint32_t[ports_arraysize];
        doParsimArrayUnpacking(b,this->ports,ports_arraysize);
    }
}

const char * OFP_Features_Reply::getDatapath_id() const
{
    return this->datapath_id.c_str();
}

void OFP_Features_Reply::setDatapath_id(const char * datapath_id)
{
    this->datapath_id = datapath_id;
}

uint32_t OFP_Features_Reply::getN_buffers() const
{
    return this->n_buffers;
}

void OFP_Features_Reply::setN_buffers(uint32_t n_buffers)
{
    this->n_buffers = n_buffers;
}

uint8_t OFP_Features_Reply::getN_tables() const
{
    return this->n_tables;
}

void OFP_Features_Reply::setN_tables(uint8_t n_tables)
{
    this->n_tables = n_tables;
}

uint32_t OFP_Features_Reply::getCapabilities() const
{
    return this->capabilities;
}

void OFP_Features_Reply::setCapabilities(uint32_t capabilities)
{
    this->capabilities = capabilities;
}

uint32_t OFP_Features_Reply::getReserved() const
{
    return this->reserved;
}

void OFP_Features_Reply::setReserved(uint32_t reserved)
{
    this->reserved = reserved;
}

void OFP_Features_Reply::setPortsArraySize(unsigned int size)
{
    uint32_t *ports2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = ports_arraysize < size ? ports_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        ports2[i] = this->ports[i];
    for (unsigned int i=sz; i<size; i++)
        ports2[i] = 0;
    ports_arraysize = size;
    delete [] this->ports;
    this->ports = ports2;
}

unsigned int OFP_Features_Reply::getPortsArraySize() const
{
    return ports_arraysize;
}

uint32_t OFP_Features_Reply::getPorts(unsigned int k) const
{
    if (k>=ports_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", ports_arraysize, k);
    return this->ports[k];
}

void OFP_Features_Reply::setPorts(unsigned int k, uint32_t ports)
{
    if (k>=ports_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", ports_arraysize, k);
    this->ports[k] = ports;
}

class OFP_Features_ReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OFP_Features_ReplyDescriptor();
    virtual ~OFP_Features_ReplyDescriptor();

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

Register_ClassDescriptor(OFP_Features_ReplyDescriptor)

OFP_Features_ReplyDescriptor::OFP_Features_ReplyDescriptor() : omnetpp::cClassDescriptor("openflow::OFP_Features_Reply", "openflow::Open_Flow_Message")
{
    propertynames = nullptr;
}

OFP_Features_ReplyDescriptor::~OFP_Features_ReplyDescriptor()
{
    delete[] propertynames;
}

bool OFP_Features_ReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OFP_Features_Reply *>(obj)!=nullptr;
}

const char **OFP_Features_ReplyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OFP_Features_ReplyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OFP_Features_ReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int OFP_Features_ReplyDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *OFP_Features_ReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "datapath_id",
        "n_buffers",
        "n_tables",
        "capabilities",
        "reserved",
        "ports",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int OFP_Features_ReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "datapath_id")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "n_buffers")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "n_tables")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "capabilities")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "ports")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OFP_Features_ReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "uint32_t",
        "uint8_t",
        "uint32_t",
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **OFP_Features_ReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *OFP_Features_ReplyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OFP_Features_ReplyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OFP_Features_Reply *pp = (OFP_Features_Reply *)object; (void)pp;
    switch (field) {
        case 5: return pp->getPortsArraySize();
        default: return 0;
    }
}

const char *OFP_Features_ReplyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Features_Reply *pp = (OFP_Features_Reply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OFP_Features_ReplyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Features_Reply *pp = (OFP_Features_Reply *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getDatapath_id());
        case 1: return ulong2string(pp->getN_buffers());
        case 2: return ulong2string(pp->getN_tables());
        case 3: return ulong2string(pp->getCapabilities());
        case 4: return ulong2string(pp->getReserved());
        case 5: return ulong2string(pp->getPorts(i));
        default: return "";
    }
}

bool OFP_Features_ReplyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OFP_Features_Reply *pp = (OFP_Features_Reply *)object; (void)pp;
    switch (field) {
        case 0: pp->setDatapath_id((value)); return true;
        case 1: pp->setN_buffers(string2ulong(value)); return true;
        case 2: pp->setN_tables(string2ulong(value)); return true;
        case 3: pp->setCapabilities(string2ulong(value)); return true;
        case 4: pp->setReserved(string2ulong(value)); return true;
        case 5: pp->setPorts(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *OFP_Features_ReplyDescriptor::getFieldStructName(int field) const
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

void *OFP_Features_ReplyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OFP_Features_Reply *pp = (OFP_Features_Reply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace openflow

