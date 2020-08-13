{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "Untitled8.ipynb",
      "provenance": [],
      "authorship_tag": "ABX9TyPtLwMYJXKzdB7v+QdLlq4z",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/jainshubham46/online-compitition-/blob/master/Find%20the%20number%20of%20islands.cpp\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "metadata": {
        "id": "HlEX2eYXwhOe",
        "colab_type": "code",
        "colab": {
          "base_uri": "https://localhost:8080/",
          "height": 129
        },
        "outputId": "66757db0-ce53-441e-b02e-f2379331d159"
      },
      "source": [
        "Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix. \n",
        "Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).\n",
        "\n",
        "Input:\n",
        "The first line of input will be the number of testcases T, then T test cases follow. The first line of each testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .\n",
        "\n",
        "Output:\n",
        "For each testcase in a new line, print the number of islands present.\n",
        "\n",
        "Your Task:\n",
        "You don't need to read input or print anything. Your task is to complete the function findIslands() which takes the matrix A and its dimensions N and M as inputs and returns the number of islands of connected 1s present in the matrix. A 1 is said to be connected if it has another 1 around it (either of the 8 directions).\n",
        "\n",
        "Expected Time Complexity: O(N*M).\n",
        "Expected Auxiliary Space: O(N*M).\n",
        "\n",
        "Constraints:\n",
        "1 <= T <= 100\n",
        "1 <= N, M <= 100\n",
        "0 <= A[i][j] <= 1\n",
        "\n",
        "Example(To be used only for expected output) :\n",
        "Input\n",
        "2\n",
        "3 3\n",
        "1 1 0 0 0 1 1 0 1\n",
        "4 4\n",
        "1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0\n",
        "\n",
        "Output\n",
        "2\n",
        "2\n",
        "\n",
        "Explanation:\n",
        "Testcase 1: The graph will look like\n",
        "1 1 0\n",
        "0 0 1\n",
        "1 0 1\n",
        "Here, two islands will be formed\n",
        "First island will be formed by elements {A[0][0] ,  A[0][1], A[1][2], A[2][2]}\n",
        "Second island will be formed by {A[2][0]}.\n",
        "Testcase 2: The graph will look like\n",
        "1 1 0 0\n",
        "0 0 1 0\n",
        "0 0 0 1\n",
        "0 1 0 0\n",
        "Here, two islands will be formed\n",
        "First island will be formed by elements {A[0][0] ,  A[0][1], A[1][2], A[2][3]}\n",
        "Second island will be formed by {A[3][1]}."
      ],
      "execution_count": 1,
      "outputs": [
        {
          "output_type": "error",
          "ename": "SyntaxError",
          "evalue": "ignored",
          "traceback": [
            "\u001b[0;36m  File \u001b[0;32m\"<ipython-input-1-478fabbe58af>\"\u001b[0;36m, line \u001b[0;32m1\u001b[0m\n\u001b[0;31m    Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix.\u001b[0m\n\u001b[0m          ^\u001b[0m\n\u001b[0;31mSyntaxError\u001b[0m\u001b[0;31m:\u001b[0m invalid syntax\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "metadata": {
        "id": "mIi5Zrlowrhl",
        "colab_type": "code",
        "colab": {}
      },
      "source": [
        "#code\n",
        "\n",
        "#include <bits/stdc++.h>\n",
        "using namespace std;\n",
        "\n",
        "int findIslands(vector<int> A[], int N, int M);\n",
        "\n",
        "int main() {\n",
        "\n",
        "    int T;\n",
        "    cin >> T;\n",
        "    while (T--) {\n",
        "        int N, M;\n",
        "        cin >> N >> M;\n",
        "        vector<int> A[N];\n",
        "        for (int i = 0; i < N; i++) {\n",
        "            vector<int> temp(M);\n",
        "            A[i] = temp;\n",
        "            for (int j = 0; j < M; j++) {\n",
        "                cin >> A[i][j];\n",
        "            }\n",
        "        }\n",
        "        cout << findIslands(A, N, M) << endl;\n",
        "    }\n",
        "    return 0;\n",
        "}\n",
        "\n",
        "int isSafe(vector<int> M[], int row, int col, vector<vector<bool>> &visited,\n",
        "           int ROW, int COL) {\n",
        "    // Check boundary conditions for i and j. Also check if node is not already\n",
        "    // visited and is currently 1.\n",
        "    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) &&\n",
        "           (M[row][col] && !visited[row][col]);\n",
        "}\n",
        "\n",
        "void dfs(vector<int> A[], int i, int j, vector<vector<bool>> &vis, int N,\n",
        "         int M) {\n",
        "\n",
        "    int row[] = {-1, -1, -1, 0,\n",
        "                 0,  1,  1,  1}; // Check for all 8 neighbours of i and j\n",
        "    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};\n",
        "\n",
        "    vis[i][j] = true;\n",
        "\n",
        "    for (int k = 0; k < 8; k++) // Checking for all 8 neighbouring sides\n",
        "    {\n",
        "        if ((i + row[k] < N && j + col[k] < M) &&\n",
        "            (isSafe(A, i + row[k], j + col[k], vis, N,\n",
        "                    M))) {\n",
        "            dfs(A, i + row[k], j + col[k], vis, N,\n",
        "                M); \n",
        "        }\n",
        "    }\n",
        "}\n",
        "\n",
        "int findIslands(vector<int> A[], int N, int M) {\n",
        "    vector<vector<bool>> visited(\n",
        "        N,\n",
        "        vector<bool>(\n",
        "            M, false)); \n",
        "    int count = 0;      \n",
        "    for (int i = 0; i < N; i++) \n",
        "    {\n",
        "        for (int j = 0; j < M; j++) {\n",
        "            if (!visited[i][j] and A[i][j]) {\n",
        "                                             \n",
        "                dfs(A, i, j, visited, N, M);  \n",
        "                // exit(0);\n",
        "                count += 1;\n",
        "            }\n",
        "        }\n",
        "    }\n",
        "    return count;\n",
        "}\n"
      ],
      "execution_count": null,
      "outputs": []
    }
  ]
}