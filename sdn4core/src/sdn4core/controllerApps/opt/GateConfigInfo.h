class GateConfigInfo {
public:
    int link_source;
    int link_dest;
    int port;
    int gate_index; //serviceClass
    float gate_frequency;

    GateConfigInfo(){
         link_source = -1;
         link_dest = -1;
         port = -1;
         gate_index = -1;
         gate_frequency = -1;
    };

    GateConfigInfo(int ls,  int ld, int p, int gi,  float gf){
        link_source = ls;
        link_dest = ld;
        port = p;
        gate_index = gi;
        gate_frequency = gf;
    }

    GateConfigInfo& operator=(const GateConfigInfo& a) {
        link_source = a.link_source;
        link_dest = a.link_dest;
        port = a.port;
        gate_index = a.gate_index;
        gate_frequency = a.gate_frequency;
        return *this;
    }

    GateConfigInfo(const GateConfigInfo &a) {
        link_source = a.link_source;
        link_dest = a.link_dest;
        port = a.port;
        gate_index = a.gate_index;
        gate_frequency = a.gate_frequency;
    }

    bool operator==(const GateConfigInfo& a) {
        if((a.link_source == link_source) &&  (a.port == port) && (a.gate_index == gate_index)&& (a.gate_frequency == gate_frequency))
            return true;
        else
            return false;
    }

};
