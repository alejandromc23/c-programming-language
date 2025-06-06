#include <stdio.h>

int main() 
{
    int i, j, k, freq, c, max;
    int af[127]; // 127 ascii characters

    freq = 0;
    max = 0;

    for (i = 0; i <= 127; i++) {
        af[i] = 0;
    }

    while((c = getchar()) != EOF) {
        ++af[c];

        if (af[c] > max) max = af[c];
    }

    for (i = 0; i<=127; i++) {
        printf("asci character %d:", i);
        for (j = 1; j<=af[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// Test
// Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, "Lorem ipsum dolor sit amet..", comes from a line in section 1.10.32.
//
// The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from "de Finibus Bonorum et Malorum" by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham.
//

// Result
// asci character 0:
// asci character 1:
// asci character 2:
// asci character 3:
// asci character 4:
// asci character 5:
// asci character 6:
// asci character 7:
// asci character 8:
// asci character 9:
// asci character 10:###
// asci character 11:
// asci character 12:
// asci character 13:
// asci character 14:
// asci character 15:
// asci character 16:
// asci character 17:
// asci character 18:
// asci character 19:
// asci character 20:
// asci character 21:
// asci character 22:
// asci character 23:
// asci character 24:
// asci character 25:
// asci character 26:
// asci character 27:
// asci character 28:
// asci character 29:
// asci character 30:
// asci character 31:
// asci character 32:##############################################################################################################################################################################
// asci character 33:
// asci character 34:######
// asci character 35:
// asci character 36:
// asci character 37:
// asci character 38:
// asci character 39:
// asci character 40:#
// asci character 41:#
// asci character 42:
// asci character 43:
// asci character 44:#############
// asci character 45:#
// asci character 46:#####################
// asci character 47:
// asci character 48:##########
// asci character 49:#############
// asci character 50:####
// asci character 51:#######
// asci character 52:###
// asci character 53:###
// asci character 54:
// asci character 55:
// asci character 56:
// asci character 57:#
// asci character 58:
// asci character 59:
// asci character 60:
// asci character 61:
// asci character 62:
// asci character 63:
// asci character 64:
// asci character 65:
// asci character 66:####
// asci character 67:#######
// asci character 68:
// asci character 69:###
// asci character 70:##
// asci character 71:#
// asci character 72:##
// asci character 73:######
// asci character 74:
// asci character 75:
// asci character 76:#########
// asci character 77:###
// asci character 78:
// asci character 79:
// asci character 80:
// asci character 81:
// asci character 82:###
// asci character 83:##
// asci character 84:####
// asci character 85:
// asci character 86:#
// asci character 87:
// asci character 88:
// asci character 89:
// asci character 90:
// asci character 91:
// asci character 92:
// asci character 93:
// asci character 94:
// asci character 95:
// asci character 96:
// asci character 97:##################################################
// asci character 98:############
// asci character 99:###############################
// asci character 100:#############################
// asci character 101:#####################################################################################
// asci character 102:###################
// asci character 103:##########
// asci character 104:#######################
// asci character 105:###########################################################
// asci character 106:
// asci character 107:######
// asci character 108:###########################
// asci character 109:##################################
// asci character 110:#################################################
// asci character 111:###############################################################################
// asci character 112:###################
// asci character 113:
// asci character 114:###############################################################
// asci character 115:######################################################
// asci character 116:#####################################################
// asci character 117:############################
// asci character 118:#####
// asci character 119:####
// asci character 120:###
// asci character 121:###########
// asci character 122:
// asci character 123:
// asci character 124:
// asci character 125:
// asci character 126:
// asci character 127:
