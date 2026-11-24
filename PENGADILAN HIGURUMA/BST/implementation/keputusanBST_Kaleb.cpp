#include "../header/keputusanBST.h"

// Fungsi bantu rekursif untuk menghapus node BST
adrPutusan deleteNodeRekursif(adrPutusan root, string nomor_putusan, adrPutusan &deletedNode) {
    if (root == nullptr) return nullptr;

    if (nomor_putusan < root->info.nomor_putusan) {
        root->left = deleteNodeRekursif(root->left, nomor_putusan, deletedNode);
    } else if (nomor_putusan > root->info.nomor_putusan) {
        root->right = deleteNodeRekursif(root->right, nomor_putusan, deletedNode);
    } else {
        // Node ditemukan
        if (root->left == nullptr) {
            adrPutusan temp = root->right;
            deletedNode = root;
            return temp;
        } else if (root->right == nullptr) {
            adrPutusan temp = root->left;
            deletedNode = root;
            return temp;
        }

        // Node dengan 2 anak: cari inorder successor (terkecil di subtree kanan)
        adrPutusan succ = root->right;
        while (succ->left != nullptr) {
            succ = succ->left;
        }

        root->info = succ->info;
        root->right = deleteNodeRekursif(root->right, succ->info.nomor_putusan, deletedNode);
    }
    return root;
}

void deleteNodePutusan(BST &T, adrPutusan &P) {
    if (isEmptyBST(T) || P == nullptr) return;
    string targetNomor = P->info.nomor_putusan;
    adrPutusan deletedNode = nullptr;
    T.root = deleteNodeRekursif(T.root, targetNomor, deletedNode);
    if (deletedNode != nullptr) {
        bool isTargetFreed = (P == deletedNode);
        dealokasiPutusan(deletedNode);
        if (isTargetFreed) {
            P = nullptr;
        }
    }
}

void deletePutusanByNomor(BST &T, string nomor_putusan) {
    adrPutusan target = findPutusan(T, nomor_putusan);
    if (target != nullptr) {
        deleteNodePutusan(T, target);
    }
}

void printInOrder(adrPutusan root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << "[" << root->info.nomor_putusan << "] Perkara: " << root->info.nomor_perkara
             << " | Hakim: " << root->info.id_hakim
             << " | Terdakwa: " << root->info.id_terdakwa
             << " | Tgl: " << root->info.tanggal_putusan
             << " | Keputusan: " << root->info.hasil_keputusan
             << " (" << root->info.jenis_hukuman << ")"
             << " | Banding: " << root->info.status_banding << endl;
        printInOrder(root->right);
    }
}

void printPreOrder(adrPutusan root) {
    if (root != nullptr) {
        cout << "[" << root->info.nomor_putusan << "] Perkara: " << root->info.nomor_perkara
             << " | Keputusan: " << root->info.hasil_keputusan << endl;
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(adrPutusan root) {
    if (root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << "[" << root->info.nomor_putusan << "] Perkara: " << root->info.nomor_perkara
             << " | Keputusan: " << root->info.hasil_keputusan << endl;
    }
}

adrPutusan findMinPutusan(BST T) {
    if (isEmptyBST(T)) return nullptr;
    adrPutusan curr = T.root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

adrPutusan findMaxPutusan(BST T) {
    if (isEmptyBST(T)) return nullptr;
    adrPutusan curr = T.root;
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr;
}

int heightBST(adrPutusan root) {
    if (root == nullptr) return 0;
    int leftHeight = heightBST(root->left);
    int rightHeight = heightBST(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodesBST(adrPutusan root) {
    if (root == nullptr) return 0;
    return 1 + countNodesBST(root->left) + countNodesBST(root->right);
}
