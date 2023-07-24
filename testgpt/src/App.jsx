import React, { useState } from "react";

function App() {
  const [text, setText] = useState("");

  return (
    <div>
      <button>Generate Random Text</button>
      <p></p>
    </div>
  );
}

export default App;
