# vsockets tools README #

VMware Player/Workstation/ESXi supports “VMware vsockets”, which a vendor-specific socket interface for communication between the host and the guest machine

* not to be confused with TCP/IP sockets
* vsockets have a different address familly

VMware Player has port “vsockets[connection-oriented]/976” open, for communication with the guest OS and the VMware tools running in the guest

* vsockets_nc: similar to “nc” but supporting additionally 
    * vsockets tcp => vsockets tunneling
    * tunnel persistency for multiple connections
    * can be very useful to integrate with tcp/ip oriented tools

* vsockets_hostname: returns the guest's CID (the ID used for vsockets communications)

### What is this repository for? ###

* Quick summary
    + Network tools for VMware vsockets
* Version: 0.12
    + working on Linux and Windows
* Tools:
    + vsockets_nc
    + vsockets_hostname
* Documentation
    + Paper: https://www.academia.edu/25202828/VMware_vsockets_tools_vsockets_nc_and_vsockets_hostname_

### How do I get set up? ###

* Download ZIP
* Unzip and run from the command-line

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### "vsockets_nc" Usage guidelines ###

/// Ligação guest => host

~~~~
[root@localhost:/vmfs/volumes/5548c165-50642975-ae44-000c29bd161f/ftp] ./vsockets_nc -l 5000
VMware vsockets environment properties
=======================================
vmci address familly=56
vmci is present
vmci local CID=2
vmware ESXi host machine detected (CID=0)
vmci listening in port 5000
vmci socket=5
...listening in port:5000
Accepted connection from CID=942803562 , port=1029
Read 3 bytes from channel 1
oi
Wrote 3 bytes to channel 2
Read 9 bytes from channel 1
como vai
Wrote 9 bytes to channel 2
o hospedeiro vai bem
Read 21 bytes from channel 2
Wrote 21 bytes to channel 1
~~~~


//// Erro quando o CID remoto não existe

~~~~
[root@localhost:/vmfs/volumes/5548c165-50642975-ae44-000c29bd161f/ftp] ./vsockets_nc -c 942893562 -s 7000
VMware vsockets environment properties
=======================================
vmci address familly=56
vmci is present
vmci local CID=2
vmware ESXi host machine detected (CID=0)
...Connecting to CID=942893562 : Port:7000
vmci connecting to=[CID]942893562:7000
vmci socket=5
connect: Invalid argument
Closing vmci socket 5
...Connection failed: Invalid argument
~~~~

/// Ligação  host => guest

~~~~
[root@localhost:/vmfs/volumes/5548c165-50642975-ae44-000c29bd161f/ftp] ./vsockets_nc -c 942803562 -s 7000
VMware vsockets environment properties
=======================================
vmci address familly=56
vmci is present
vmci local CID=2
vmware ESXi host machine detected (CID=0)
...Connecting to CID=942803562 : Port:7000
vmci connecting to=[CID]942803562:7000
vmci socket=5
...Connection established to CID=942803562 : Port:7000
~~~~

### vsockets_hostname examples ###

#### Windows VMWare Player Host ###

~~~~
D:\vsockets tools [GIT]\src\target\bin>vsockets_hostname.exe
VMware vsockets environment properties
=======================================
VMware vmci address familly=28
VMware vmci is present
VMware vmci local CID=2
VMware Hypervisor host machine detected (CID=2)
~~~~


### ESXi port scans ###

* guest => CID=2 : só vê os portos novos abertos pelo vsockets_nc
* guest => CID=0 : vê o porto 976 aberto
* guest => guest : só vê os portos novos abertos pelo vsockets_nc

* host => guest : só vê os portos novos abertos pelo vsockets_nc
   * (fica muito lento, o ESXi deve dar pouca prioridade a processos lançados na linha de comandos)

* host => CID=0 : não vê nenhum porto aberto
   * (fica muito lento, o ESXi deve dar pouca prioridade a processos lançados na linha de comandos)

* host => CID=2 : vê porto 2222 aberto

### VMware Player 7 port scans ###

* guest => host (CID=2) : só vê os portos novos abertos pelo vsockets_nc
* guest => hypervisor (CID=0) : vê o porto 976 aberto
* guest => guest : só vê os portos novos abertos pelo vsockets_nc

* host => CID=2 : não vê nada aberto 
* host => CID=0 : não vê nada aberto


### References ###

* VMware vSockets references
   + http://pubs.vmware.com/vsphere-60/topic/com.vmware.ICbase/PDF/ws9_esx60_vmci_sockets.pdf

* Open Source
    + http://www.smashingmagazine.com/2013/01/starting-an-open-source-project/

* Dependencies
    * liblist: http://ohnopub.net/~ohnobinki/liblist/doc/

### Donations ###

![Bitcoin-accepted-here-printable.png](https://bitbucket.org/repo/XE88rK/images/1985448334-Bitcoin-accepted-here-printable.png)

* Bitcoin address: 18T5tnGrUyKMnYw59bi7h2tt8CvEu19KrG
* Bitcoin URI: bitcoin:18T5tnGrUyKMnYw59bi7h2tt8CvEu19KrG?label=vsockets%20donations&message=vsockets%20development%20support%20donations

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact