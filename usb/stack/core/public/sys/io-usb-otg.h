

/*51*//*<bcfb8>*/typedef struct _io_usb_otg_dll_entry io_usb_otg_dll_entry_t;
/*52*//*<bd053>*/typedef struct _usb_hcd usb_hcd_t;
/*53*//*<bd0ee>*/typedef struct _usb_dcd usb_dcd_t; 

/*60*//*<bd202>*/struct _iousb_endpoint_t {
    usbd_endpoint_descriptor_t/*->usbdi.h*/ edesc; //0
    uint32_t flags; //8
    void* user; //12 = 0xc
    //16
};

/*64*//*<bd233>*/typedef struct _iousb_endpoint_t iousb_endpoint_t;

/*70*//*<bd23e>*/struct _iousb_device {
    uint32_t device_address; //0
    uint32_t device_port; //4
    uint32_t device_speed; //8
    uint32_t flags; //12 = 0xc
    uint32_t nports; //16 = 0x10
    //20
};

/*79*//*<bd287>*/typedef struct _iousb_device iousb_device_t;

/*82*//*<bd292>*/struct _iousb_transfer {
    uint32_t status; //0
    uint32_t flags; //4
    uint32_t usbdi_flags; //8
    uint32_t timeout; //12 = 0xc
    uint32_t isoch_frame; //16 = 0x10
    uint8_t* buffer; //20 = 0x14
    paddr64_t buffer_paddr; //24 = 0x18
    uint32_t buffer_len; //32 = 0x20
    uint32_t actual_len; //36 = 0x24
    /*<bd323>*/void (*urb_complete_cbf)(iousb_endpoint_t*, struct _iousb_transfer*, uint32_t, uint32_t); //40 = 0x28
    void* xdata_ptr; //44 = 0x2c
    //48
};

/*94*//*<bd34f>*/typedef struct _iousb_transfer iousb_transfer_t;

/*100*//*<bd35a>*/struct _usb_hcd_self {
    uint32_t nfuncs; //0
    int (*hc_bus_state)(); //4
    int (*hc_port_status_change)(); //8
    int (*hc_port_resume_signalling)(); //12 = 0xc
    iousb_device_t* (*iousb_get_parent_device)(); //16 = 0x10
    iousb_endpoint_t* (*iousb_get_endpoint)(); //20 = 0x14
    /*<bd449>*/int (*hc_reserved)(usb_hcd_t*, void*); //24 = 0x18
    //28
};

/*108*//*<bd463>*/typedef struct _usb_hcd_self usb_hcd_self_t;


/*116*//**/struct _usb_dcd_self {
    //TODO!!!
    //36
};

/*128*//*<bd5e9>*/typedef struct _usb_dcd_self usb_dcd_self_t;

/*153*//*<bd643>*/struct _iousb_pipe_methods {
    /*<bd68c>*/int (*iousb_endpoint_enable)(void*, iousb_device_t*, iousb_endpoint_t*); //0
    /*<bd6ab>*/int (*iousb_endpoint_disable)(void*, iousb_endpoint_t*); //4
    /*<bd6c5>*/int (*iousb_transfer_data)(void*, iousb_transfer_t*, iousb_endpoint_t*, uint8_t*, uint32_t, uint32_t); //8
    //TODO!!!
    //20
};

/*159*//**/typedef struct _iousb_pipe_methods iousb_pipe_methods_t;

/*173*//*<bd73f>*/struct _iousb_ep_pipe_methods {
    iousb_pipe_methods_t* ctrl_pipe_methods; //0
    iousb_pipe_methods_t* isoch_pipe_methods; //4
    iousb_pipe_methods_t* bulk_pipe_methods; //8
    iousb_pipe_methods_t* int_pipe_methods; //12
    //16
};

/*178*//*<bd782>*/typedef struct _iousb_ep_pipe_methods iousb_ep_pipe_methods_t;

/*183*//*<bd78d>*/struct _usb_hcd_methods {
    int nentries; //0
    /*<bd85a>*/int (*hc_init)(usb_hcd_t*, uint32_t, char*); //4
    /*<bd879>*/int (*hc_start)(usb_hcd_t*); //8
    /*<bd879>*/int (*hc_stop)(usb_hcd_t*); //12 = 0xc
    /*<bd879>*/int (*hc_shutdown)(usb_hcd_t*); //16 = 0x10
    //TODO!!!
    //64
};


/*202*//*<bd8ed>*/typedef struct _usb_hcd_methods usb_hcd_methods_t;

/*336*//*<bcfc3>*/struct _io_usb_otg_dll_entry {
    //TODO!!!
    //40
};


/*361*//*<bdbae>*/struct _iousb_hw_ctrl {
    char* cname; //0
    struct pci_dev_info* pci_inf; //4
    uint32_t cindex; //8
    uint32_t rsvd; //12 = 0xc
    uint64_t capabilities; //16 = 0x10
    uint32_t max_transfer_size; //24 = 0x18
    uint32_t max_unaligned_xfer; //28 = 0x1c
    uint64_t buff_alignment_mask; //32 = 0x20
    //40
};

/*370*//*<bdc2a>*/typedef struct _iousb_hw_ctrl iousb_hw_ctrl_t;

/*376*//*<bd05e>*/struct _usb_hcd {
    iousb_hw_ctrl_t hw_ctrl; //0
    usb_hcd_self_t* hcd_self; //40
    void* pdev; //44 = 0x2c
    uint32_t num_root_hubs; //48 = 0x30
    uint32_t root_hub_status; //52 = 0x34
    uint32_t AvailableBandwidth; //56 = 0x38
    uint32_t ctrl_retry; //60 = 0x3c
    uint32_t HFrameumber; //64 = 0x40
    void* dll_hdl; //68 = 0x44
    void* hc_data; //72 = 0x48
    //TODO!!!
    //80
};


/*512*//*<bd0f9>*/struct _usb_dcd {
    iousb_hw_ctrl_t hw_ctrl; //0
    usb_dcd_self_t* dcd_self; //40
    //TODO!!!
    //80
};



