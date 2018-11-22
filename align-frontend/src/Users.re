let component = ReasonReact.statelessComponent("Users");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App">
        <h1>(ReasonReact.string("Welcome to the users page"))</h1>
    </div>,
};
