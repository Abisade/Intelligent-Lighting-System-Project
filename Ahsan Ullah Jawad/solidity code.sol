//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;

contract Factory{
    
    uint idDigits = 16;
    uint idModulus= 10**idDigits;
    struct Product {
        string name; 
        uint id;
    
      
    }
    Product[] public products;  
    event NewProduct(uint ArrayProductid, string name, uint id);
    function _createProduct (string memory _name, uint _id) private{
      // uint ArrayProductid=products.push(Product(_name, _id))-1;
      uint ArrayProductid=products.length-1;
      products.push(Product(_name, _id));
      uint productid=products.length-1;
      
      emit NewProduct(ArrayProductid, _name, _id);
      
        
    } 
    function _generateRandomId(string memory _str) private view 
    returns (uint){
        
        uint rand= uint(keccak256(abi.encodePacked(_str)));
        return rand%idModulus;
    
    }
    function createRandomProduct(string memory _name) public returns (uint) {
        uint randld=_generateRandomId(_name);
        _createProduct(_name, randld);
    }
    mapping (address=> uint) productToOwner;

    mapping (address=>uint) ownerProductCount; 

    function Ownership(uint productid) public {
        productToOwner[msg.sender]=productid;
        ownerProductCount[msg.sender]=productid++;
    }
    function getProductsByOwner(address _owner) external view returns (uint[] memory) {
        uint counter=0;
        uint LengthOfArray=ownerProductCount[_owner];
        uint[] memory result= new uint[](LengthOfArray); 
    for (uint i=0; i<products.length; i++){
        if (productToOwner[i] ==_owner){
            result[counter]=i;
            counter++;
        }
    }
    return result;
    }
    mapping (uint=> uint) age;

    modifier olderThan( uint _age, uint _userld) {
        require (
            _userld >=_age,
        );
        _;
    }
    function validationUsers(uint _userld) public view {
        modifier olderThan(18, _userld){

        }
        _;
    }

    


    
    
}