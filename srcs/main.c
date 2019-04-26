/*
** EPITECH PROJECT, 2019
** my main functions
** File description:
** made by Martin Vantalon
*/

#include "../include/mychap.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void print(char const *str)
{
    int i;
    i = 0;
    while (str[i] != '\0' ) {
		my_putchar(str[i]);
		i = i + 1;
    }
}
unsigned short csum(unsigned short *buf, int nwords)
{
    unsigned long sum;
    for(sum=0; nwords>0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum &0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

int main(int ac, char **av)
{
    if (ac == 7) {
        my_parsing(ac, av);
    }
    return 0;
}

//./rawudp 192.168.10.10 21
int init_connexion(char *target, int port)
{
    int sd;
    char buffer[PCKT_LEN];
    struct ipheader *ip = (struct ipheader *) buffer;
    struct udpheader *udp = (struct udpheader *) (buffer + sizeof(struct ipheader));
    struct sockaddr_in sin;
    int one = 1;
    const int *val = &one;
    memset(buffer, 0, PCKT_LEN);

    sd = socket(PF_INET, SOCK_RAW, IPPROTO_UDP);

    if(sd < 0) {
        perror("socket() error");
        exit(84);
    }
    else
        printf("socket() - Using SOCK_RAW socket and UDP protocol is OK.\n");

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(target);

    ip->iph_ihl = 5;
    ip->iph_ver = 4;
    ip->iph_tos = 16; // Low delay
    ip->iph_len = sizeof(struct ipheader) + sizeof(struct udpheader);
    ip->iph_ident = htons(54321);
    ip->iph_ttl = 64; // hops
    ip->iph_protocol = 17; // UDP
    ip->iph_sourceip = inet_addr(target);

    udp->udph_srcport = htons(port);
    udp->udph_len = htons(sizeof(struct udpheader));
    ip->iph_chksum = csum((unsigned short *)buffer, sizeof(struct ipheader) + sizeof(struct udpheader));

    if(setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("setsockopt() error");
        exit(84);
    }
    else
        printf("setsockopt() is OK.\n");
    printf("Trying...\n");
    printf("Using raw socket and UDP protocol\n");
    printf("Using Source IP: %s port: %u.\n", target, port);

    int count;
    for(count = 1; count <=20; count++) {
        if(sendto(sd, buffer, ip->iph_len, 0, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
            perror("sendto() error");
            exit(-1);
        } else {
            printf("Count #%u - sendto() is OK.\n", count);
            sleep(2);
        }
    }
    close(sd);
    return 0;
}
