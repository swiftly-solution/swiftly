> [!note]
> The methods to get the clients are preset in [UserMessage](/plugin-docs/scripting/usermessages/usermessage) class: AddClient, RemoveClient, ClearClients, AddClients and GetClients.

#### How can I stop the execution of a User Message?
Simply return `EventResult.Stop` and it will be blocked.

#### How can I get the UserMessage?
To get the user message object, you need to use [GetUserMessage](/plugin-docs/scripting/utils/misc/getusermessage) along with the `usermessage_uuid` parameter.