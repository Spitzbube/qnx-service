

#ifndef __NTO_IO_USBOTG_H_INCLUDED
#define __NTO_IO_USBOTG_H_INCLUDED


#include <inttypes.h>

#include <sys/dispatch.h>
#include <sys/types.h>

#include <sys/usb100.h>
#include <sys/usbdi.h>





































/*51*//*<bcfb8>*/typedef struct _io_usb_otg_dll_entry io_usb_otg_dll_entry_t;
/*52*//*<bd053>*/typedef struct _usb_hcd usb_hcd_t;
/*53*//*<bd0ee>*/typedef struct _usb_dcd usb_dcd_t; 






typedef /*60*//*<bd202>*/struct _iousb_endpoint_t {
    usbd_endpoint_descriptor_t/*->usbdi.h*/ edesc; //0
    uint32_t flags; //8
    void* user; //12 = 0xc
} /*64*//*<bd233>*/ iousb_endpoint_t; //size: 16





typedef /*70*//*<bd23e>*/struct _iousb_device {
    uint32_t device_address; //0
    uint32_t device_port; //4
    uint32_t device_speed; //8
    uint32_t flags; //12 = 0xc
    uint32_t nports; //16 = 0x10

    

} /*79*//*<bd287>*/ iousb_device_t; //size: 20


typedef /*82*//*<bd292>*/struct _iousb_transfer {
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
} /*94*//*<bd34f>*/ iousb_transfer_t; //size: 48





typedef /*100*//*<bd35a>*/struct _usb_hcd_self {
    uint32_t nfuncs; //0
    /*102*//*<4151>*/int (*hc_bus_state)(usb_hcd_t*, uint32_t, uint32_t); //4
    /*103*//*<cfe3>*/int (*hc_port_status_change)(usb_hcd_t*, uint32_t); //8
    /*104*//*<cffd>*/ int (*hc_port_resume_signalling)(usb_hcd_t*, uint32_t); //12 = 0xc
    /*105*//*<d018>*/iousb_device_t* (*iousb_get_parent_device)(iousb_device_t*); //16 = 0x10
    /*106*//*<d032>*/iousb_endpoint_t* (*iousb_get_endpoint)(iousb_device_t*, int); //20 = 0x14
    /*107*//*<d04c>*/int (*hc_reserved)(usb_hcd_t*, void*); //24 = 0x18
} /*108*//*<bd463>*/ usb_hcd_self_t; //size: 28







typedef /*116*//**/struct _usb_dcd_self {
    /*117*//*<2f9f>*/uint32_t nfuncs; //0
    /*118*//*<4278>*/int (*usbdc_device_state_change)(usb_dcd_t*, uint32_t); //4
    /*119*//*<4292>*/int (*usbdc_endpoint_state_change)(iousb_endpoint_t*, uint32_t); //8
    /*120*//*<42ac>*/int usbdc_setup_packet_process; //12
    /*121*//*<42c2>*/int usbdc_set_device_speed; //16
    /*122*//*<42dc>*/int usbdc_reserved; //20

    /*124*//*<4320>*/int usbdc_vhd_init; //24
    /*125*//*<42dc>*/int usbdc_vhd_detach; //28
    /*126*//*<435a>*/int usbdc_vhd_attach; //32

} /*128*//*<bd5e9>*/ usb_dcd_self_t; //size: 36












typedef /*141*//*<4396>*/ struct _iousb_self {
    /*142*//*<436b>*/ union {
        /*143*//*<438a>*/usb_hcd_self_t* hcd; //0
        /*144*//*<4390>*/usb_dcd_self_t* dcd; //0

    }/*146*//*<436b>*/ self; //0
} /*147*//*<48e0>*/ iousb_self_t; //size: 4





typedef /*153*//*<bd643>*/struct _iousb_pipe_methods {
    /*<bd68c>*/int (*iousb_endpoint_enable)(void*, iousb_device_t*, iousb_endpoint_t*); //0
    /*<bd6ab>*/int (*iousb_endpoint_disable)(void*, iousb_endpoint_t*); //4
    /*<bd6c5>*/int (*iousb_transfer_data)(void*, iousb_transfer_t*, iousb_endpoint_t*, uint8_t*, uint32_t, uint32_t); //8
    /*157*//*<bd718>*/int (*iousb_transfer_abort)(void*, iousb_transfer_t*, iousb_endpoint_t*); //12
    /*158*//*<bd72e>*/int (*reserved)(void*, void*); //16
} /*159*//**/ iousb_pipe_methods_t; //size: 20













typedef /*173*//*<bd73f>*/struct _iousb_ep_pipe_methods {
    iousb_pipe_methods_t* ctrl_pipe_methods; //0
    iousb_pipe_methods_t* isoch_pipe_methods; //4
    iousb_pipe_methods_t* bulk_pipe_methods; //8
    iousb_pipe_methods_t* int_pipe_methods; //12
} /*178*//*<bd782>*/ iousb_ep_pipe_methods_t; //size: 16




typedef /*183*//*<bd78d>*/struct _usb_hcd_methods {
    int nentries; //0
    /*<bd85a>*/int (*hc_init)(usb_hcd_t*, uint32_t, char*); //4
    /*<bd879>*/int (*hc_start)(usb_hcd_t*); //8
    /*<bd879>*/int (*hc_stop)(usb_hcd_t*); //12 = 0xc
    /*<bd879>*/int (*hc_shutdown)(usb_hcd_t*); //16 = 0x10
    /*189*//*<c2ffc>*/int (*hc_set_bus_state)(usb_hcd_t*, uint32_t); //20
    /*190*//*<c3490>*/void* (*hc_dma_memory_malloc)(usb_hcd_t*, size_t); //24
    /*191*//*<c34af>*/int (*hc_dma_memory_free)(usb_hcd_t*, void*, size_t); //28
    /*192*//*<c3476>*/int (*hc_interrupt)(usb_hcd_t*); //32
    /*193*//*<c2fc8>*/int (*hc_set_port_feature)(usb_hcd_t*, uint32_t, uint32_t); //36
    /*194*//*<c2fc8>*/int (*hc_clear_port_feature)(usb_hcd_t*, uint32_t, uint32_t); //40
    /*195*//*<c34cf>*/int (*hc_check_port_status)(usb_hcd_t*, uint32_t*); //44
    /*196*//*<c2ffc>*/int (*hc_check_device_connected)(usb_hcd_t*, uint32_t); //48
    /*197*//*<c2ffc>*/int (*hc_get_root_device_speed)(usb_hcd_t*, uint32_t); //52
    /*198*//*<c3476>*/int (*hc_get_current_frame)(usb_hcd_t*); //56

    /* pipe handling methods 			*/
    /*201*//*<c34d5>*/iousb_ep_pipe_methods_t* ep_pipe_methods; //60
} /*202*//*<bd8ed>*/ usb_hcd_methods_t; //size: 64


























typedef /*229*//*<1cd732>*/ struct _usb_dcd_methods {
    //TODO!!!
























}/*255*//*<1cd923>*/ usb_dcd_methods_t; //size: 68


























































typedef /*314*//*<1cd92e>*/ struct _usb_otg_methods {


} /*317*//*<1cd937>*/ usb_otg_methods_t; //size: 0





typedef /*323*//*<1cd985>*/ struct _usb_controller_methods {
    /*324*//*<1cd985>*/usb_hcd_methods_t* hc_methods; //0
    /*325*//*<1cd98b>*/usb_dcd_methods_t* dc_methods; //4
//		usb_rhub_methods_t	*rhub_methods;
    /*327*//*<1cd991>*/usb_otg_methods_t* otg_methods; //8
    /*328*//*<1cc336>*/void* reserved; //12
} /*329*//*<1cd943>*/ usb_controller_methods; //size: 16






/*336*//*<bcfc3>*/struct _io_usb_otg_dll_entry {
    /*337*//**/char* name; //0
    /*338*//**/uint32_t version; //4
    /*339*//**/uint32_t rsvd; //8
    /*340*//**/uint32_t device_interest; //12
    /*341*//**/uint32_t vid; //16
    /*342*//**/uint32_t did; //20
    /*343*//**/uint32_t ctrl_type; //24
    
    /*345*//*<48e0>*/int (*init)(void*, dispatch_t*, iousb_self_t*, char*); //28
    /*346*//*<490a>*/int (*shutdown)(void*); //32
    /*347*//*<1cd9e2>*/usb_controller_methods* usbctrl_methods; //36
}; //size: 40












typedef /*361*//*<bdbae>*/struct _iousb_hw_ctrl {
    char* cname; //0
    struct pci_dev_info* pci_inf; //4
    uint32_t cindex; //8
    uint32_t rsvd; //12 = 0xc
    uint64_t capabilities; //16 = 0x10
    uint32_t max_transfer_size; //24 = 0x18
    uint32_t max_unaligned_xfer; //28 = 0x1c
    uint64_t buff_alignment_mask; //32 = 0x20
} /*370*//*<bdc2a>*/ iousb_hw_ctrl_t; //size: 40





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
}; //size: 80




























































































































/*512*//*<bd0f9>*/struct _usb_dcd {
    iousb_hw_ctrl_t hw_ctrl; //0
    usb_dcd_self_t* dcd_self; //40
    /*515*//*<bb49d>*/uint32_t priority; //44
    /*516*//*<bb49d>*/uint32_t verbosity; //48
    /*517*//*<bb518>*/char* serial_string; //52

    /*519*//*<bb47c>*/uint8_t selected_config; //56
    /*520*//*<bb542>*/uint8_t rsrvd[3]; //57

    /*522*//*<bc476>*/uint8_t* setup_buf; //60
    /*523*//*<bb15f>*/void* drvr_hdl; //64
    /*524*//*<bb15f>*/void* dc_data; //68
    /*525*//*<bb15f>*/void* dll_hdl; //72
}; //size: 80


#endif

