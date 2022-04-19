//SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.5.0 <0.8.0;               //Exercise:1

contract Factory {                            //Exercise:2
    uint idDigits = 16;
    uint idModulus = 10^uint(idDigits);       //Exercise:3


    struct Product{                           //Exercise:4
        string name;
        uint id;
    }
    Product[] public products;                //Exercise:5

    event NewProduct (uint ArrayProductId,  string name, uint id);      //Exercise:6

    function _createProduct(string memory _name, uint _id) private {
        products.push(Product(_name,_id));
        uint productId= (products.length - 1);
        emit NewProduct(productId,_name,_id); 
    }


    function _generateRandomId(string memory _str) private view returns (uint){            //Exercise:7
        uint rand=uint(keccak256(abi.encodePacked(_str)));                                 
        return (rand%idModulus);
    }

    function createRandomProduct(string memory _name) public {
        uint randId=_generateRandomId(_name);                                            //Exercise:8
        _createProduct(_name, randId);
    }
    
    
    mapping (uint => address) public productToOwner;                           //Exercise:10
    mapping (address => uint) ownerProductCount;


    function _Ownership (uint _productId) private { 
        productToOwner[_productId] = msg.sender;                             //Exercise:11
        ownerProductCount[msg.sender]++;
    }


    function getProductsByOwner (address _owner) external view returns(uint[] memory) { 
        uint counter=0;
        uint[] memory result= new uint[](ownerProductCount[_owner]);                          //Exercise:12
        for (uint i=0; i<products.length; i++) {
            if (productToOwner[i]==_owner) {
                result[counter]=i;
                counter++;
            }
        }
        return result;
    }

    mapping (uint => uint) public age; 

    modifier olderThan (uint _age, uint _userId) {
        require (age[_userId] >= _age, "You Must Be At Least 18 Years Old");                //Exercise:14
        _;
    }

    function validationUsers (uint _userId) public olderThan(18, _userId) {
    }

}
