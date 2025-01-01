


#include "obj.h"
#include "pci.h"
#include "io-usb-otg.h"














/*21*//*<bb6fc>*/typedef struct _usb_controller_entry usb_controller_entry_t;
/*22*//*<bb7c6>*/typedef struct _usb_hc usb_hc_t;

/*44*//*<bfa4b>*/struct _usb_ctrl_common {
    uint32_t controller_type; //0
    uint32_t cindex; //4
    int chid; //8
    int coid; //12 = 0xc
    int tid; //16 = 0x10
    void* pdev; //20 = 0x14
    uint32_t irq; //24 = 0x18
    uint32_t usb_iid; //28 = 0x1c
    //32
};

/*53*//*<bfab8>*/typedef struct _usb_ctrl_common usb_ctrl_common_t;

/*56*//*<bb7d1>*/struct _usb_hc {
    usb_hcd_t hcd; //0
    usb_ctrl_common_t hw_ctrl; //80 = 0x50 +0x20
    iousb_ep_pipe_methods_t* hw_ep_pipe_methods; //112 = 0x70
    usb_hcd_methods_t* hcd_methods; //116 = 0x74
    //TODO!!!
    //960
};


/*87*//*<bfb1b>*/struct _usb_dc {
    usb_dcd_t dcd; //0
    //TODO!!!
    //176
};


/*113*//*<bfbf4>*/typedef struct _usb_dc usb_dc_t;


/*122*//*<bb707>*/struct _usb_controller_entry {
    obj_t* obj; //0
    uint32_t controller_type; //4
    uint32_t flags; //8
    int chid; //12 = 0xc
    int coid; //16 = 0x10
    int tid; //20 = 0x14
    void* pdev; //24 = 0x18
    uint32_t usb_iid; //28 = 0x1c
    struct pci_dev_info* pci_inf; //32 = 0x20
    usb_hc_t* hc; //36 = 0x24
    usb_dc_t* dc; //40 = 0x28
    //TODO!!! 
    //60
};

